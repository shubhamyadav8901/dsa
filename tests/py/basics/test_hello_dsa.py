import unittest

from py.basics.hello_dsa import sum_to_n_formula, sum_to_n_loop


class TestSumToN(unittest.TestCase):
    def test_small_cases(self):
        self.assertEqual(sum_to_n_loop(0), 0)
        self.assertEqual(sum_to_n_loop(1), 1)
        self.assertEqual(sum_to_n_loop(10), 55)

    def test_formula_matches_known_values(self):
        self.assertEqual(sum_to_n_formula(0), 0)
        self.assertEqual(sum_to_n_formula(1), 1)
        self.assertEqual(sum_to_n_formula(10), 55)

    def test_both_implementations_agree(self):
        for n in range(0, 201):
            self.assertEqual(sum_to_n_loop(n), sum_to_n_formula(n), f"disagreed at n={n}")


if __name__ == "__main__":
    unittest.main()
