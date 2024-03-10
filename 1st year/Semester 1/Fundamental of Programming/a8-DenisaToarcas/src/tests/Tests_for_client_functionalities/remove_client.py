import unittest

from src.domain.client import Client
from src.repository.client_repo import ClientRepository

class Remove_client_tests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_remove_client_1(self):
        print("test")
        first_client = Client(1234, "Iliesiu Diana")
        client_repo = ClientRepository()

        client_repo.add_client(first_client)
        initial_length = len(client_repo)

        client_repo.remove_client(first_client.client_id)

        self.assertEqual(len(client_repo), initial_length - 1)

    def test_remove_client_2(self):
        print("test")
        first_client = Client(1234, "Iliesiu Diana")
        second_client = Client(1212, "Popescu Emanuela")
        client_repo = ClientRepository()

        client_repo.add_client(first_client)
        initial_length = len(client_repo)

        client_repo.remove_client(second_client.client_id)

        self.assertEqual(len(client_repo), initial_length - 1)
