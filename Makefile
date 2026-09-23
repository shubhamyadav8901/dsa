# ---------------------------------------------------------------------------
# DSA learning environment - build & test runner
#
#   make help                              show this help
#   make run FILE=cpp/basics/hello_dsa.cpp run one file (.cpp / .py / .java)
#   make test                              run every test, all languages
#   make test L=cpp                        run only C++ tests
#   make test T=arrays                     run only the 'arrays' topic
#   make test L=py T=arrays                combine both filters
#   make clean                             delete build output
# ---------------------------------------------------------------------------

CXX      ?= clang++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -g -fsanitize=address,undefined -I.
JAVAC    ?= javac
JAVA     ?= java
PY       ?= python3
BUILD    := build

LANGUAGES := cpp py java

# Optional filters (may be empty)
L ?=
T ?=

.PHONY: help run test test-cpp test-py test-java clean

help:
	@echo ""
	@echo "  make run FILE=<path>      compile+run one file (.cpp .py .java)"
	@echo "  make test                 run all tests in all languages"
	@echo "  make test L=cpp|py|java   restrict to one language"
	@echo "  make test T=<topic>       restrict to one topic (e.g. arrays)"
	@echo "  make clean                remove build output"
	@echo ""
	@echo "  Example: make run FILE=cpp/basics/hello_dsa.cpp"
	@echo "  Example: make test L=cpp T=basics"
	@echo ""

# --- run a single file ------------------------------------------------------
run:
	@test -n "$(FILE)" || { echo "Usage: make run FILE=cpp/basics/hello_dsa.cpp"; exit 1; }
	@test -f "$(FILE)" || { echo "No such file: $(FILE)"; exit 1; }
	@case "$(FILE)" in \
	  *.cpp) mkdir -p $(BUILD)/bin; \
	         out="$(BUILD)/bin/`basename '$(FILE)' .cpp`"; \
	         $(CXX) $(CXXFLAGS) "$(FILE)" -o "$$out" && "$$out" ;; \
	  *.py)  PYTHONPATH=. $(PY) "$(FILE)" ;; \
	  *.java) mkdir -p $(BUILD)/java; \
	         $(JAVAC) -d $(BUILD)/java "$(FILE)" && \
	         $(JAVA) -cp $(BUILD)/java "`basename '$(FILE)' .java`" ;; \
	  *) echo "Don't know how to run: $(FILE)"; exit 1 ;; \
	esac

# --- tests ------------------------------------------------------------------
# Every language runs even when an earlier one fails, so one broken C++ test
# never hides a broken Python test.
test:
	@case "|$(L)" in \
	  "|"|"|cpp"|"|py"|"|java") ;; \
	  *) echo "Unknown language: $(L)   (use L=cpp, L=py or L=java)"; exit 1 ;; \
	esac
	@test -z "$(T)" || test -d "cpp/$(T)" || { \
	  echo "Unknown topic: $(T)"; \
	  echo "Topics: `ls cpp | tr '\n' ' '`"; exit 1; }
	@fail=0; \
	 for lang in $(if $(L),$(L),$(LANGUAGES)); do \
	   $(MAKE) --no-print-directory test-$$lang T="$(T)" || fail=1; \
	 done; \
	 exit $$fail

test-cpp:
	@echo "=== C++ tests ==="
	@dir="tests/cpp$(if $(T),/$(T))"; \
	 files=`find "$$dir" -name '*_test.cpp' 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (no C++ tests yet in $$dir)"; exit 0; fi; \
	 mkdir -p $(BUILD)/bin; fail=0; \
	 for f in $$files; do \
	   out="$(BUILD)/bin/`basename $$f .cpp`"; \
	   if $(CXX) $(CXXFLAGS) "$$f" -o "$$out"; then \
	     "$$out" || fail=1; \
	   else \
	     echo "  COMPILE FAILED: $$f"; fail=1; \
	   fi; \
	 done; \
	 exit $$fail

# Python's unittest prints its own format; its output is captured so that a
# passing run reports the same one-line PASS as C++ and Java, and a failing run
# prints everything unittest had to say.
test-py:
	@echo "=== Python tests ==="
	@dir="tests/py$(if $(T),/$(T))"; \
	 files=`find "$$dir" -name 'test_*.py' 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (no Python tests yet in $$dir)"; exit 0; fi; \
	 mkdir -p $(BUILD); fail=0; \
	 for f in $$files; do \
	   log="$(BUILD)/`basename $$f .py`.log"; \
	   if PYTHONPATH=. $(PY) "$$f" > "$$log" 2>&1; then \
	     n=`sed -n 's/^Ran \([0-9][0-9]*\) test.*/\1/p' "$$log"`; \
	     echo "  PASS  $$f  ($$n tests)"; \
	   else \
	     cat "$$log"; \
	     echo "  FAILED $$f"; fail=1; \
	   fi; \
	 done; \
	 exit $$fail

test-java:
	@echo "=== Java tests ==="
	@dir="tests/java$(if $(T),/$(T))"; \
	 files=`find "$$dir" -name '*Test.java' 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (no Java tests yet in $$dir)"; exit 0; fi; \
	 mkdir -p $(BUILD)/java; fail=0; \
	 for f in $$files; do \
	   cls=`basename "$$f" .java`; \
	   name=`echo "$$cls" | sed 's/Test$$//'`; \
	   topic=`basename \`dirname "$$f"\``; \
	   srcs="tests/java/Check.java $$f"; \
	   if [ -f "java/$$topic/$$name.java" ]; then srcs="$$srcs java/$$topic/$$name.java"; fi; \
	   if $(JAVAC) -d $(BUILD)/java $$srcs; then \
	     $(JAVA) -cp $(BUILD)/java "$$cls" || fail=1; \
	   else \
	     echo "  COMPILE FAILED: $$f"; fail=1; \
	   fi; \
	 done; \
	 exit $$fail

clean:
	@rm -rf $(BUILD)
	@find . -name '__pycache__' -type d -prune -exec rm -rf {} + 2>/dev/null || true
	@echo "Cleaned."

# --- formatting -------------------------------------------------------------
# clang-format handles both C++ and Java. It ships with the Xcode Command Line
# Tools, so it needs no install; it is just not on PATH by default.
CLANG_FORMAT ?= $(shell command -v clang-format 2>/dev/null || xcrun -f clang-format 2>/dev/null)
FORMAT_DIRS  := cpp java tests

.PHONY: fmt fmt-check

fmt:
	@test -n "$(CLANG_FORMAT)" || { echo "clang-format not found. Install the Xcode Command Line Tools: xcode-select --install"; exit 1; }
	@files=`find $(FORMAT_DIRS) \( -name '*.cpp' -o -name '*.hpp' -o -name '*.java' \) 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (nothing to format)"; exit 0; fi; \
	 $(CLANG_FORMAT) -i $$files && echo "  formatted `echo $$files | wc -w | tr -d ' '` files"
	@if command -v black >/dev/null 2>&1; then \
	   black --quiet --line-length 100 py tests/py && echo "  formatted Python with black"; \
	 else \
	   echo "  (skipping Python: no formatter installed - 'pip install black' to enable)"; \
	 fi

fmt-check:
	@test -n "$(CLANG_FORMAT)" || { echo "clang-format not found. Install the Xcode Command Line Tools: xcode-select --install"; exit 1; }
	@files=`find $(FORMAT_DIRS) \( -name '*.cpp' -o -name '*.hpp' -o -name '*.java' \) 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (nothing to check)"; exit 0; fi; \
	 if $(CLANG_FORMAT) --dry-run -Werror $$files; then \
	   echo "  all `echo $$files | wc -w | tr -d ' '` files are formatted"; \
	 else \
	   echo ""; echo "  Run 'make fmt' to fix."; exit 1; \
	 fi
