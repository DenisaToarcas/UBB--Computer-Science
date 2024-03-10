import unittest

from src.domain.client import Client

class ClientTests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_client_class_1(self):
        print("test")
        first_client = Client(1111, "Alina Creanga")
        self.assertEqual(first_client.client_id, 1111)
        self.assertEqual(first_client.name, "Alina Creanga")
        first_client.client_id = 1222
        self.assertEqual(first_client.client_id, 1222)
        first_client.name = "Alina Pop"
        self.assertEqual(first_client.name, "Alina Pop")

    def test_client_class_2(self):
        print("test")
        first_client = Client(1090, "Tara Luana")
        self.assertEqual(first_client.client_id, 1111)
        self.assertEqual(first_client.name, "Alina Creanga")