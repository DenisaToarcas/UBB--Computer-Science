from TripleDictGraph import TripleDictGraph
from TripleDictGraph import read_graph_from_file
from TripleDictGraph import write_graph_to_file
from TripleDictGraph import lowest_length_path
from TripleDictGraph import minimum_cost_walk_Floyd_Warshall
from TripleDictGraph import is_DAG
from TripleDictGraph import topological_sort
from TripleDictGraph import calculate_earliest_starting_time
from TripleDictGraph import calculate_latest_starting_time
from TripleDictGraph import find_critical_activities
from TripleDictGraph import read_graph_from_file_work_4
import random


class UI:
    def __init__(self):
        """self.__tripleGraph = tripleGraph
        self.__input_file = input_file"""
        self.__graphs = []
        self.__current_graph = 0

    def addEmptyGraph(self):
        graph = TripleDictGraph()
        self.__graphs.append(graph)
        self.__current_graph = len(self.__graphs) - 1
        print("Graph added!")

    def get_number_of_vertices(self):
        if len(self.__graphs) > 0:
            print("The number of vertices is: ", self.__graphs[self.__current_graph].number_of_vertices())
        else:
            raise Exception("There is no graph added!")

    def get_number_of_edges(self):
        if len(self.__graphs) > 0:
            print("The number of edges is: ", self.__graphs[self.__current_graph].number_of_edges())
        else:
            raise Exception("There is no graph added!")

    def is_edge_ui(self):
        print("Give the 2 vertices:")
        vertex_1 = input("first vertex >>>")
        vertex_2 = input("second vertex>>>")
        if self.__graphs[self.__current_graph].is_edge(int(vertex_1), int(vertex_2)) is True:
            print("Yes, there is an edge going from the first to the second vertex")
        else:
            print("No, there is no edge going from the first to the second vertex")

    def in_degree_ui(self):
        print("Give the vertex for which to find the in-degree:")
        vertex = input(">>>")
        if self.__graphs[self.__current_graph].is_vertex(int(vertex)) is True:
            print("The in-degree of the given vertex is: ", self.__graphs[self.__current_graph].in_degree(int(vertex)))
        else:
            print("This vertex is not part of the graph!")

    def out_degree_ui(self):
        print("Give the vertex for which to find the out-degree:")
        vertex = input(">>>")
        if self.__graphs[self.__current_graph].is_vertex(int(vertex)) is True:
            print("The out-degree of the given vertex is: ", self.__graphs[self.__current_graph].out_degree(int(vertex)))
        else:
            print("This vertex is not part of the graph!")

    def retrieve_info_edge(self):
        print("Give vertices of the edge:")
        vertex_1 = input("first vertex >>>")
        vertex_2 = input("second vertex>>>")
        if self.__graphs[self.__current_graph].is_vertex(int(vertex_1)) is True:
            if self.__graphs[self.__current_graph].is_vertex(int(vertex_2)) is True:
                if self.__graphs[self.__current_graph].is_edge(int(vertex_1), int(vertex_2)) is True:
                    print("The cost of the edge is: ", self.__graphs[self.__current_graph].retrieve_edge(int(vertex_1),
                                                                                                         int(vertex_2)))
                else:
                    print("There is no edge going from the first to the second vertex")
            else:
                print("There is no edge going from the first to the second vertex")
        else:
            print("There is no edge going from the first to the second vertex")

    def modify_info_edge(self):
        print("Give vertices of the edge:")
        vertex_1 = input("first vertex >>>")
        vertex_2 = input("second vertex>>>")
        print("The new cost of the edge will be: ")
        new_cost = input(">>>")
        result = self.__graphs[self.__current_graph].modify_cost_of_edge(int(vertex_1), int(vertex_2),
                                                                         int(new_cost))
        if result is True:
            print("The modification was successful!")
        else:
            print("There is no edge going from the first to the second vertex")

    def add_edge(self):
        print("Give info about edge:")
        vertex_1 = input("first vertex >>>")
        vertex_2 = input("second vertex>>>")
        print("The cost of the edge will be: ")
        new_cost = input(">>>")
        if self.__graphs[self.__current_graph].is_vertex(int(vertex_1)) is True and self.__graphs[
            self.__current_graph].is_vertex(int(vertex_2)) is True:
            result = self.__graphs[self.__current_graph].add_edge(int(vertex_1), int(vertex_2),
                                                                  int(new_cost))
            if result is True:
                print("The adding was successful!")
            else:
                print("There is an edge going from the first to the second vertex")
        else:
            print("The vertices are not part of the graph!")

    def remove_edge(self):
        print("Give info about edge:")
        vertex_1 = input("first vertex >>>")
        vertex_2 = input("second vertex>>>")
        if self.__graphs[self.__current_graph].is_vertex(int(vertex_1)) is True and self.__graphs[
            self.__current_graph].is_vertex(int(vertex_2)) is True:
            result = self.__graphs[self.__current_graph].remove_edge(int(vertex_1), int(vertex_2))

            if result is True:
                print("The removing was successful!")
            else:
                print("There is no edge going from the first to the second vertex")
        else:
            print("The vertices are not part of the graph!")

    def add_vertex(self):
        print("Give the vertex:")
        vertex = input(">>>")
        result = self.__graphs[self.__current_graph].add_vertex(int(vertex))
        if result is True:
            print("The adding was successful!")
        else:
            print("This vertex is already part of the graph")

    def remove_vertex(self):
        print("Give the vertex:")
        vertex = input(">>>")
        result = self.__graphs[self.__current_graph].remove_vertex(int(vertex))
        if result is True:
            print("The remove was successful!")
        else:
            print("This vertex is not part of the graph")

    def copy_graph(self):
        graph_copy = self.__graphs[self.__current_graph].make_copy_of_graph()
        self.__graphs.append(graph_copy)

    def parse_vertices(self):
        if self.__graphs[self.__current_graph].number_of_vertices() != 0:
            print("The vertices of the graph are:")
            for vertex in self.__graphs[self.__current_graph].parse_vertices():
                print("{}".format(vertex))
        else:
            print("Graph is empty!")

    def parse_inbound_edges(self):
        vertex = int(input("Enter the vertex: "))
        vertex = int(input("Enter the vertex: "))
        line = str(vertex) + " :"
        for y in self.__graphs[self.__current_graph].parse_inbound_edges(vertex):
            line = line + " " + "{} ".format(str(y))
        print(line)

    def parse_outbound_edges(self):
        vertex = int(input("Enter the vertex: "))
        line = str(vertex) + " :"
        for y in self.__graphs[self.__current_graph].parse_outbound_edges(vertex):
            line = line + " " + "{} ".format(str(y))
        print(line)

    def read_graph_from_file(self):
        filename = input("Enter the name of the file: ")
        graph = read_graph_from_file(filename)
        self.__graphs.append(graph)
        self.__current_graph = len(self.__graphs) - 1

    def write_graph_to_file(self):
        current_graph = self.__graphs[self.__current_graph]
        output_file = "output" + str(self.__current_graph) + ".txt"
        write_graph_to_file(current_graph, output_file)

    def switch_graph(self):
        print("You are on the graph number: {}".format(self.__current_graph))
        print("Available graphs: 0 - {}".format(str(len(self.__graphs) - 1)))
        number = input("Enter the graph number you want to switch to: ")
        if 0 <= int(number) <= len(self.__graphs):
            self.__current_graph = int(number)
        else:
            raise ValueError("Trying to switch to a non existing graph!")

    def create_random_graph_ui(self):
        vertices = int(input("Enter the number of vertices: "))
        edges = int(input("Enter the number of edges: "))
        graph = self.generate_random(vertices, edges)
        self.__graphs.append(graph)
        self.__current_graph = len(self.__graphs) - 1

    def generate_random(self, vertices, edges):
        if edges > vertices * vertices:
            raise ValueError("Too many edges!")
        graph = TripleDictGraph()
        i = 0
        while i <= edges:
            x = random.randint(0, vertices)
            y = random.randint(0, vertices)
            cost = random.randint(0, 500)
            if graph.is_vertex(x) is False:
                graph.add_vertex(x)
            if graph.is_vertex(y) is False:
                graph.add_vertex(y)
            if graph.add_edge(x, y, cost) is True:
                i += 1
        return graph

    def lowest_length_path_ui(self):
        graph = self.__graphs[self.__current_graph]
        starting_vertex = int(input("Introduce the starting vertex:"))
        ending_vertex = int(input("Introduce the ending vertex:"))

        if graph.is_vertex(starting_vertex) is False or graph.is_vertex(ending_vertex) is False:
            raise Exception("The vertices are not part of the graph")

        path, length = lowest_length_path(graph, starting_vertex, ending_vertex)
        print("The minimum length between " + str(starting_vertex) + " and " + str(ending_vertex) + " is = " + str(length))
        print("The path is:")
        for vertex in path:
            print(vertex)

    def minimum_cost_walk_Floyd_Warshall_ui(self):
        graph = self.__graphs[self.__current_graph]
        starting_vertex = int(input("Introduce the starting vertex:"))
        ending_vertex = int(input("Introduce the ending vertex:"))

        if graph.is_vertex(starting_vertex) is False or graph.is_vertex(ending_vertex) is False:
            raise Exception("The vertices are not part of the graph")

        cost, path, list_of_intermediate_matrices = minimum_cost_walk_Floyd_Warshall(graph, starting_vertex, ending_vertex)
        print("The minimum cost walk between " + str(starting_vertex) + " and " + str(ending_vertex) + " is = " + str(cost))
        print("The path is:")
        for vertex in path:
            print(vertex)

        print()
        print("Intermediate matrices:\n")
        for matrix in list_of_intermediate_matrices:
            for line in matrix:
                print(line)
            print()

    def is_DAG(self):
        graph = self.__graphs[self.__current_graph]
        print("Is the current graph a DAG?")
        print(is_DAG(graph))

    def topological_sort(self):
        graph = self.__graphs[self.__current_graph]
        if is_DAG(graph) is False:
            print("The current graph is not a DAG!")
        else:
            sorted_activities = topological_sort(graph)
            print("The topological sorted list is:")
            print(sorted_activities)

    def get_earliest_and_latest_starting_time(self):
        graph = self.__graphs[self.__current_graph]

        if is_DAG(graph) is False:
            print("The current graph is not a DAG!")
        else:
            earliest_starts = calculate_earliest_starting_time(graph)
            latest_starts = calculate_latest_starting_time(graph)

            print("Earliest starts:")
            for vertex in earliest_starts.keys():
                print(vertex, " earliest starting time: ", earliest_starts[vertex])

            print("Latest starts:")
            for vertex in latest_starts.keys():
                print(vertex, " latest starting time: ", latest_starts[vertex])

            total_duration = max(calculate_earliest_starting_time(graph).values())
            print("Total duration:", total_duration)


    def find_critical_activities(self):
        graph = self.__graphs[self.__current_graph]
        if is_DAG(graph) is False:
            print("The current graph is not a DAG!")
        else:
            critical_activities = find_critical_activities(graph)
            if critical_activities is None:
                print("There are no critical activities!")
            else:
                print("The critical activities are:")
                print(critical_activities)

    def read_graph_from_file_work_4(self):
        filename = input("Enter the name of the file: ")
        graph = read_graph_from_file_work_4(filename)
        self.__graphs.append(graph)
        self.__current_graph = len(self.__graphs) - 1

    def menu(self):
        print("\nMenu:")
        print("e. EXIT")
        print("0. Add an empty graph")
        print("1. Get the number of vertices")
        print("2. Get the number of edges")
        print("3. Edge between two given vertices")
        print("4. In degree of a specified vertex")
        print("5. Out degree of a specified vertex")
        print("6. Retrieve info of a specified edge")
        print("7. Modify info of a specified edge")
        print("8. Add edge")
        print("9. Remove edge")
        print("10. Add vertex")
        print("11. Remove vertex")
        print("12. Copy graph")
        print("13. Read graph from text file")
        print("14. Write graph from text file")
        print("15. Parse the number of vertices")
        print("16. Parse inbound edges of a vertex")
        print("17. Parse outbound edges of a vertex")
        print("18. Switch to different graph")
        print("19. Generate random graph")
        print("20. Lowest length path backwards BFS")
        print("21. Minimum cost walk between 2 vertices - Floyd Warshall")
        print("PRACTICAL WORK NO. 4:")
        print("22. Verify if graph is DAG")
        print("23. Topological sort of the graph")
        print("24. Get earliest and latest starting times")
        print("25. Find critical activities")
        print("r. read_graph_from_file_work_4")
        print("Introduce the option here:")

    def print_menu(self):
        while True:
            try:
                self.menu()
                option_chosen = input(">>>")
                if len(option_chosen) > 2:
                    while len(option_chosen) > 2:
                        print("Invalid option introduced!")
                        print("PLease introduce a different option!")
                        option_chosen = input(">>>")

                if option_chosen == "e":
                    break
                elif option_chosen == "0":
                    self.addEmptyGraph()
                elif option_chosen == "1":
                    self.get_number_of_vertices()
                elif option_chosen == "2":
                    self.get_number_of_edges()
                elif option_chosen == "3":
                    self.is_edge_ui()
                elif option_chosen == "4":
                    self.in_degree_ui()
                elif option_chosen == "5":
                    self.out_degree_ui()
                elif option_chosen == "6":
                    self.retrieve_info_edge()
                elif option_chosen == "7":
                    self.modify_info_edge()
                elif option_chosen == "8":
                    self.add_edge()
                elif option_chosen == "9":
                    self.remove_edge()
                elif option_chosen == "10":
                    self.add_vertex()
                elif option_chosen == "11":
                    self.remove_vertex()
                elif option_chosen == "12":
                    self.copy_graph()
                elif option_chosen == "13":
                    self.read_graph_from_file()
                elif option_chosen == "14":
                    self.write_graph_to_file()
                elif option_chosen == "15":
                    self.parse_vertices()
                elif option_chosen == "16":
                    self.parse_inbound_edges()
                elif option_chosen == "17":
                    self.parse_outbound_edges()
                elif option_chosen == "18":
                    self.switch_graph()
                elif option_chosen == "19":
                    self.create_random_graph_ui()
                elif option_chosen == "20":
                    self.lowest_length_path_ui()
                elif option_chosen == "21":
                    self.minimum_cost_walk_Floyd_Warshall_ui()
                elif option_chosen == "22":
                    self.is_DAG()
                elif option_chosen == "23":
                    self.topological_sort()
                elif option_chosen == "24":
                    self.get_earliest_and_latest_starting_time()
                elif option_chosen == "25":
                    self.find_critical_activities()
                elif option_chosen == "r":
                    self.read_graph_from_file_work_4()
            except Exception as e:
                print(e)
