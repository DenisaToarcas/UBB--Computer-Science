import unittest

from src.domain.client import Client
from src.repository.client_repo import ClientRepository

class Add_client_tests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_add_client_1(self):
        print("test")
        """
            First, we verify if we can add a new client to the list 
        """
        first_client = Client(1234, "Iliesiu Diana")
        client_repo = ClientRepository()
        initial_length = len(client_repo)
        client_repo.add_client(first_client)
        self.assertEqual(len(client_repo), initial_length + 1)

        """
            And here, we try to add the same client for the second time, which should fail
        """
        length_after_first_addition = len(client_repo)
        client_repo.add_client(first_client)
        self.assertEqual(len(client_repo), length_after_first_addition + 1)

    def test_add_client_2(self):
        print("test")
        second_client = Client(1234, "Ana Pop")
        client_repo = ClientRepository()
        initial_length = len(client_repo)
        client_repo.add_client(second_client)
        self.assertEqual(len(client_repo), initial_length + 1)
