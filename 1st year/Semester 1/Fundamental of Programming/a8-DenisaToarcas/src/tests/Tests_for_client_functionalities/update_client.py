import unittest

from src.domain.client import Client
from src.repository.client_repo import ClientRepository

class Update_client_tests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_update_client_1(self):
        print("test")
        first_client = Client(1234, "Iliesiu Diana")
        second_client = Client(1234, "Anamaria Popovici")
        client_repo = ClientRepository()
        client_repo_for_test =ClientRepository()

        client_repo.add_client(first_client)
        client_repo.update_client(second_client)
        client_repo_for_test.add_client(second_client)

        self.assertEqual(client_repo.get_all_clients_from_list(), client_repo_for_test.get_all_clients_from_list())

    def test_update_client_2(self):
        print("test")
        first_client = Client(1234, "Iliesiu Diana")
        second_client = Client(1212, "Anamaria Popovici")
        client_repo = ClientRepository()
        client_repo_for_test = ClientRepository()

        client_repo.add_client(first_client)
        client_repo.update_client(second_client)
        client_repo_for_test.add_client(second_client)

        self.assertEqual(client_repo.get_all_clients_from_list(), client_repo_for_test.get_all_clients_from_list())
