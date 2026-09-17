"""Copy to: tests/py/<topic>/test_<snake_case_name>.py

Run with: make test L=py T=<topic>
"""

import unittest

from py.<topic>.<snake_case_name> import solve


class TestSolve(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(solve(), 0)

    def test_edge_cases(self):
        # Smallest input, empty input, and the case you expect to get wrong.
        pass


if __name__ == "__main__":
    unittest.main()
