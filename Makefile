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
test:
	@$(MAKE) --no-print-directory $(if $(L),test-$(L),test-cpp test-py test-java) T="$(T)"

test-cpp:
	@echo "=== C++ tests ==="
	@dir="tests/cpp$(if $(T),/$(T))"; \
	 files=`find "$$dir" -name '*_test.cpp' 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (no C++ tests found in $$dir)"; exit 0; fi; \
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

test-py:
	@echo "=== Python tests ==="
	@dir="tests/py$(if $(T),/$(T))"; \
	 files=`find "$$dir" -name 'test_*.py' 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (no Python tests found in $$dir)"; exit 0; fi; \
	 fail=0; \
	 for f in $$files; do \
	   PYTHONPATH=. $(PY) "$$f" || fail=1; \
	 done; \
	 exit $$fail

test-java:
	@echo "=== Java tests ==="
	@dir="tests/java$(if $(T),/$(T))"; \
	 files=`find "$$dir" -name '*Test.java' 2>/dev/null | sort`; \
	 if [ -z "$$files" ]; then echo "  (no Java tests found in $$dir)"; exit 0; fi; \
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
