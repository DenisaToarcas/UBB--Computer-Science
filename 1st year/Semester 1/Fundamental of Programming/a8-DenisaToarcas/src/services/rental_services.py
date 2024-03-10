from src.domain.rental import Rental
from src.domain.rental import RentalValidator
from src.repository.rental_repo import RentalRepository

from datetime import date

class RentalServices:
    def __init__(self, rental_repository: RentalRepository, rental_validator: RentalValidator):
        self.__rental_repository = rental_repository
        self.__rental_validator = rental_validator

    def add_rental(self, new_rental: Rental):
        self.__rental_repository.add_rental(new_rental)

    def rent_a_movie(self, rental_id, movie_id, client_id, rented_date, due_date, returned_date):
        """
            1.We build the rental instance
            2.Validate it
            3.Adds the rental to the list of rentals
        """
        new_rental = Rental(rental_id, movie_id, client_id, rented_date, due_date, returned_date)
        self.__rental_validator.validate(new_rental)
        self.__rental_repository.rent_a_movie(new_rental)

    def return_a_movie(self, movie_id, client_id):
        self.__rental_repository.return_a_movie(movie_id, client_id)

    def get_all_rentals_from_list(self):
        return self.__rental_repository.get_all_rentals_from_list()

    """
           Functions for CREATING STATISTICS
       """

    """
        1. FUNCTIONS FOR GETTING THE MOST RENTED MOVIES
    """

    def find_ids_of_rented_movies(self):
        """
        :return: A list of the ids of the rented movies, arranged in descending order with regard to the number of days
        they have been rented
        """
        verified_movies = []
        days_for_movies = []
        maximum_date = date(9999, 12, 31)

        rental_list = self.__rental_repository.get_all_rentals()

        for rental in rental_list:
            if rental.movie_id not in verified_movies:
                verified_movies.append(rental.movie_id)
                if rental.returned_date != maximum_date:
                    days_for_movies.append((rental.returned_date - rental.rented_date).days + 1)
                else:
                    today = date.today()
                    days_for_movies.append((today - rental.rented_date).days + 1)

            else:
                if rental.returned_date != maximum_date:
                    days_for_movies[verified_movies.index(rental.movie_id)] = \
                        days_for_movies[verified_movies.index(rental.movie_id)] + \
                        (rental.returned_date - rental.rented_date).days + 1
                else:
                    today = date.today()
                    days_for_movies[verified_movies.index(rental.movie_id)] = \
                        days_for_movies[verified_movies.index(rental.movie_id)] + \
                        (today - rental.rented_date).days + 1

        for i in range(0, len(days_for_movies)):
            for j in range(i + 1, len(days_for_movies)):
                if days_for_movies[i] < days_for_movies[j]:
                    auxiliary = days_for_movies[i]
                    days_for_movies[i] = days_for_movies[j]
                    days_for_movies[j] = auxiliary

                    auxiliary = verified_movies[i]
                    verified_movies[i] = verified_movies[j]
                    verified_movies[j] = auxiliary

        return verified_movies

    def find_titles_of_rented_movies(self, movie_ids: list):
        list_of_names_of_most_rented_movies = []

        rental_list = self.__rental_repository.get_all_rentals()

        for rental in rental_list:
            if rental.movie_id in movie_ids and \
                    self.__rental_repository.get_movie_name(rental.movie_id) not in list_of_names_of_most_rented_movies:
                list_of_names_of_most_rented_movies.append(self.__rental_repository.get_movie_name(rental.movie_id))

        return list_of_names_of_most_rented_movies

    def most_rented_movies(self):
        return self.find_titles_of_rented_movies(self.find_ids_of_rented_movies())

    """
        2.FUNCTIONS FOR GETTING THE MOST ACTIVE CLIENTS
    """

    def get_ids_of_clients(self):
        """
        :return: A list of ids of the clients, sorted in descending order with regard to the number of movies' rented
        days
        """
        verified_clients = []
        days_for_movies = []
        maximum_date = date(9999, 12, 31)
        rental_list = self.__rental_repository.get_all_rentals()

        for rental in rental_list:
            if rental.client_id not in verified_clients:
                verified_clients.append(rental.client_id)
                if rental.returned_date != maximum_date:
                    days_for_movies.append((rental.returned_date - rental.rented_date).days + 1)
                else:
                    today = date.today()
                    days_for_movies.append((today - rental.rented_date).days + 1)

            else:
                if rental.returned_date != maximum_date:
                    days_for_movies[verified_clients.index(rental.client_id)] = \
                        days_for_movies[verified_clients.index(rental.client_id)] + \
                        (rental.returned_date - rental.rented_date).days + 1
                else:
                    today = date.today()
                    days_for_movies[verified_clients.index(rental.client_id)] = \
                        days_for_movies[verified_clients.index(rental.client_id)] + \
                        (today - rental.rented_date).days + 1

        for i in range(0, len(days_for_movies)):
            for j in range(i + 1, len(days_for_movies)):
                if days_for_movies[i] < days_for_movies[j]:
                    auxiliary = days_for_movies[i]
                    days_for_movies[i] = days_for_movies[j]
                    days_for_movies[j] = auxiliary

                    auxiliary = verified_clients[i]
                    verified_clients[i] = verified_clients[j]
                    verified_clients[j] = auxiliary

        return verified_clients

    def get_names_of_most_active_clients(self, clients_ids: list):
        list_of_names_of_most_active_clients = []
        rental_list = self.__rental_repository.get_all_rentals()

        for rental in rental_list:
            if rental.client_id in clients_ids and \
                    self.__rental_repository.get_client_name(rental.client_id) not in list_of_names_of_most_active_clients:
                list_of_names_of_most_active_clients.append(self.__rental_repository.get_client_name(rental.client_id))

        return list_of_names_of_most_active_clients

    def most_active_clients(self):
        return self.get_names_of_most_active_clients(self.get_ids_of_clients())

    """
        3.FUNCTIONS FOR GETTING LATE RENTALS
    """

    def late_rentals(self):
        list_of_late_rentals = []
        days_of_delay = []

        date_today = date.today()
        rental_list = self.__rental_repository.get_all_rentals_from_list()

        for rental in rental_list:
            if rental.due_date < date_today:
                list_of_late_rentals.append(rental)
                days_of_delay.append((date_today - rental.due_date).days + 1)

        for i in range(0, len(days_of_delay)):
            for j in range(i + 1, len(days_of_delay)):
                if days_of_delay[i] < days_of_delay[j]:
                    auxiliary = days_of_delay[i]
                    days_of_delay[i] = days_of_delay[j]
                    days_of_delay[j] = auxiliary

                    auxiliary = list_of_late_rentals[i]
                    list_of_late_rentals[i] = list_of_late_rentals[j]
                    list_of_late_rentals[j] = auxiliary

        return list_of_late_rentals