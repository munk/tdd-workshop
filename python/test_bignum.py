import unittest
from bignum import add

class BignumTest(unittest.TestCase):
    def test_zero_plus_n_is_n(self):
        self.assertEqual(add("1", "0"), "1")
