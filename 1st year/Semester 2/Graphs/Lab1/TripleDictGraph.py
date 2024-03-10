import copy
import sys
import queue

from collections import deque


class TripleDictGraph:
    def __init__(self):
        self.__dictionary_in = {}
        self.__dictionary_out = {}
        self.__dictionary_cost = {}

    @property
    def dictionary_in(self):
        return self.__dictionary_in

    @property
    def dictionary_out(self):
        return self.__dictionary_out

    @property
    def dictionary_cost(self):
        return self.__dictionary_cost

    def number_of_vertices(self):
        return len(self.__dictionary_in)

    def number_of_edges(self):
        return len(self.__dictionary_cost)

    def parse_vertices(self):
        """Returns an iterable containing all the vertices of the graph"""
        """It uses the .keys() method on dictionaries"""
        vertices = list(self.__dictionary_in.keys())
        for x in vertices:
            yield x

    def parse_inbound_edges(self, vertex: int):
        for x in self.__dictionary_in[vertex]:
            yield x

    def parse_outbound_edges(self, vertex: int):
        for x in self.__dictionary_out[vertex]:
            yield x

    def parse_cost(self):
        keys = list(self.__dictionary_cost)
        for k in keys:
            yield k

    def in_degree(self, vertex: int):
        """Firstly, we verify whether the vertex has in-degree"""
        if vertex not in self.__dictionary_in.keys():
            raise Exception("This vertex has no in degree!")
        return len(self.__dictionary_in[vertex])

    def out_degree(self, vertex: int):
        if vertex not in self.__dictionary_out.keys():
            raise Exception("This vertex has no out degree!")
        return len(self.__dictionary_out[vertex])

    def is_vertex(self, vertex):
        if vertex in self.__dictionary_in.keys() or vertex in self.__dictionary_out.keys():
            return True
        return False

    def add_vertex(self, new_vertex: int):
        if self.is_vertex(new_vertex) is False:
            self.__dictionary_in[new_vertex] = []
            self.__dictionary_out[new_vertex] = []
            return True
        return False

    def remove_vertex(self, vertex: int):
        if self.is_vertex(vertex) is False:
            return False
        else:
            for v in self.__dictionary_in[vertex]:
                self.__dictionary_out[v].remove(vertex)

            for v in self.__dictionary_out[vertex]:
                self.__dictionary_in[v].remove(vertex)

            self.__dictionary_in.pop(vertex)
            self.__dictionary_out.pop(vertex)

            for key in list(self.__dictionary_cost.keys()):
                if key[0] == vertex or key[1] == vertex:
                    self.__dictionary_cost.pop(key)

            return True

    def is_edge(self, x: int, y: int):
        if x in self.__dictionary_in[y] and y in self.__dictionary_out[x]:
            return True
        return False

    def add_edge(self, x: int, y: int, cost: int):
        if self.is_edge(x, y) is False:
            self.__dictionary_in[y].append(x)
            self.__dictionary_out[x].append(y)
            self.__dictionary_cost[(x, y)] = cost
            return True
        return False

    def remove_edge(self, x: int, y: int):
        if self.is_edge(x, y) is True:
            self.__dictionary_in[y].remove(x)
            self.__dictionary_out[x].remove(y)
            self.__dictionary_cost.pop((x, y))
            return True
        return False

    def modify_cost_of_edge(self, x: int, y: int, new_cost: int):
        if self.is_edge(x, y) is True:
            self.__dictionary_cost[(x, y)] = new_cost
            return True
        return False

    def retrieve_edge(self, x: int, y: int):
        if self.is_edge(x, y) is True:
            return self.__dictionary_cost[(x, y)]

    def make_copy_of_graph(self):
        return copy.deepcopy(self)


def read_graph_from_file(filename: str):
    file_descriptor = open(filename, 'rt')
    line = file_descriptor.readline()
    line = line.strip()
    vertices = -1
    line = line.split(" ")

    if len(line) == 2:
        containing_no_of_vertices_and_edges = True
        vertices = int(line[0])
        edges = int(line[1])

        line = file_descriptor.readline().strip()

    graph = TripleDictGraph()

    while len(line) > 0:
        if len(line) == 1:
            """
            If there is only one vertex on a line, it means that it is isolated
            """
            graph.add_vertex(int(line[0]))
        else:
            line = line.split(" ")
            graph.add_vertex(int(line[0]))
            graph.add_vertex(int(line[1]))
            graph.dictionary_in[int(line[1])].append(int(line[0]))
            graph.dictionary_out[int(line[0])].append(int(line[1]))
            graph.dictionary_cost[(int(line[0]), int(line[1]))] = int(line[2])
            last_added = int(line[1])

        line = file_descriptor.readline().strip()

    if vertices != -1:
        while graph.number_of_vertices() != vertices:
            graph.add_vertex(last_added + 1)
            last_added += 1
    file_descriptor.close()

    return graph


def read_graph_from_file_work_4(filename: str):
    file_descriptor = open(filename, 'rt')
    line = file_descriptor.readline()
    line = line.strip()
    line = line.split(" ")

    graph = TripleDictGraph()

    while len(line) > 0:
        if len(line) == 1:
            """
            If there is only one vertex on a line, it means that it is isolated
            """
            graph.add_vertex(line[0])
        else:
            graph.add_vertex(line[0])

            if line[1] == '-':
                graph.add_vertex(line[1])
                graph.dictionary_cost[(line[1], line[0])] = int(line[2])

            else:
                if ',' in line[1]:
                    predecessors = line[1].split(',')
                    for i in predecessors:
                        graph.add_vertex(i)
                        graph.dictionary_in[i].append(line[0])
                        graph.dictionary_out[line[0]].append(i)
                        graph.dictionary_cost[(line[0], i)] = int(line[2])
                else:
                    graph.add_vertex(line[1])
                    graph.dictionary_in[line[1]].append(line[0])
                    graph.dictionary_out[line[0]].append(line[1])
                    graph.dictionary_cost[(line[0], line[1])] = int(line[2])

        line = file_descriptor.readline().strip()
    file_descriptor.close()

    return graph


def write_graph_to_file(graph, filename: str):
    file_descriptor = open(filename, 'wt')
    if len(graph.dictionary_cost) == 0 and len(graph.dictionary_in) == 0:
        raise Exception("There is nothing to write!!!")
    else:
        first_line = str(graph.number_of_vertices) + " " + str(graph.number_of_edges) + "\n"
        file_descriptor.write(first_line)
        for key in graph.dictionary_cost.keys():
            line = ""
            line = str(key[0]) + " " + str(key[1]) + " " + str(graph.dictionary_cost[key]) + "\n"
            file_descriptor.write(line)

        for vertex in graph.dictionary_in.keys():
            if len(graph.dictionary_in[vertex]) == 0 and len(graph.dictionary_out[vertex]) == 0:
                """
                here we have an isolated vertex
                """
                line = ""
                line = str(vertex) + "\n"
                file_descriptor.write(line)
    file_descriptor.close()


def lowest_length_path(graph: TripleDictGraph, starting_vertex: int, ending_vertex: int):
    queue = deque()
    queue.append(ending_vertex)
    visited_vertices = {ending_vertex: 0}
    """visited_vertices dictionary contains as keys the vertices that are visited during 
    performing the BFS algorithm and the values represent the distance from the ending vertex
    to them"""

    while queue:
        current_vertex = queue.popleft()
        for neighbour in graph.dictionary_in[current_vertex]:
            if neighbour not in visited_vertices:
                visited_vertices[neighbour] = visited_vertices[current_vertex] + 1
                queue.append(neighbour)

                if neighbour == starting_vertex:
                    path = [starting_vertex]
                    """I create a list that contains the vertices which represent the path
                    between the starting and ending vertex"""
                    while path[-1] != ending_vertex:
                        for neighbour1 in graph.dictionary_out[path[-1]]:
                            if neighbour1 in visited_vertices and visited_vertices[neighbour1] == visited_vertices[
                                path[-1]] - 1:
                                path.append(neighbour1)
                                break

                    return path, visited_vertices[starting_vertex]
                """I return the path and also the minimum length"""
    raise Exception("There is no path between these vertices")


def minimum_cost_walk_Floyd_Warshall(graph: TripleDictGraph, starting_vertex: int, ending_vertex: int):
    """The dist matrix is the cost matrix"""
    """I initialize the matrix of distances with the maximum value for all the pairs of vertices and their
    corresponding weight of edge"""
    nodes = list(graph.dictionary_in.keys())
    nodes.sort()

    dist_matrix = [[float('inf') for _ in range(len(nodes))] for _ in range(len(nodes))]

    previous_matrix = [[0 for _ in range(len(nodes))] for _ in range(len(nodes))]

    """I switch the infinite values with 0's for the edges from the vertex to itself"""
    for i in range(len(nodes)):
        dist_matrix[i][i] = 0

    """I put in the matrix the costs of the existing edges"""
    for i in range(len(nodes)):
        vertex_i = nodes[i]
        for j in range(len(nodes)):
            vertex_j = nodes[j]
            if graph.is_edge(vertex_i, vertex_j) is True:
                dist_matrix[i][j] = graph.dictionary_cost[(vertex_i, vertex_j)]
                previous_matrix[i][j] = nodes[i]

    list_of_intermediate_matrices = []

    for k in range(len(nodes)):
        list_of_intermediate_matrices.append(copy.deepcopy(dist_matrix))
        for i in range(len(nodes)):
            for j in range(len(nodes)):
                if dist_matrix[i][j] > dist_matrix[i][k] + dist_matrix[k][j]:
                    dist_matrix[i][j] = dist_matrix[i][k] + dist_matrix[k][j]
                    previous_matrix[i][j] = previous_matrix[k][j]

                if i == j and dist_matrix[i][j] < 0:
                    raise Exception("There is a negative cost cycle!")

    if dist_matrix[nodes.index(starting_vertex)][nodes.index(ending_vertex)] == float('inf'):
        raise Exception("There is no path between these vertices!")

    path = [ending_vertex]
    end = ending_vertex

    while starting_vertex != ending_vertex:
        ending_vertex = previous_matrix[nodes.index(starting_vertex)][nodes.index(ending_vertex)]
        path.append(ending_vertex)

    return dist_matrix[nodes.index(starting_vertex)][nodes.index(end)], path[::-1], list_of_intermediate_matrices


def is_DAG(graph: TripleDictGraph):
    """
    :param graph: a TripleDictGraph, containing as nodes the activities, and as costs the duration of the every activity
    :return: True, if the actual graph is a directed acyclic graph (DAG) and False otherwise
    """
    # the is_DAG function  is used to check whether a given graph is a Directed Acyclic Graph (DAG). It performs a depth-first search (DFS) to detect cycles in the graph    visited_vertices = []
    visited_vertices = []
    stack = []

    # in the visited vertices I store the nodes that have been verified already for not taking part in a cycle

    def has_cycle(activity_node):
        if activity_node in visited_vertices:
            return False
        # this means that we have already verified this vertex
        visited_vertices.append(activity_node)
        stack.append(activity_node)

        for predecessor in graph.dictionary_in[activity_node]:
            if predecessor in stack and predecessor != activity_node or has_cycle(predecessor):
                return True

        stack.remove(activity_node)
        return False

    for node in graph.dictionary_in:
        if has_cycle(node):
            return False

    return True


def topological_sort(graph: TripleDictGraph):
    if is_DAG(graph) is False:
        return None
    else:
        sorted_activities = []
        queue_activities = deque()
        count_of_predecessors = {}

        for vertex in graph.dictionary_in:
            count_of_predecessors[vertex] = graph.in_degree(vertex)
            if count_of_predecessors[vertex] == 0:
                queue_activities.append(vertex)

        while queue_activities:
            current_activity = queue_activities.popleft()
            sorted_activities.append(current_activity)

            for successor in graph.dictionary_out[current_activity]:
                count_of_predecessors[successor] -= 1
                if count_of_predecessors[successor] == 0:
                    queue_activities.append(successor)

        return sorted_activities


def calculate_earliest_starting_time(graph: TripleDictGraph):
    # if the activities can be done simultaneously
    sorted_activities = topological_sort(graph)

    if sorted_activities is None:
        return None

    costs = {}
    for vertex in sorted_activities:
        costs[vertex] = 0

    earliest_starts = {}
    for vertex in sorted_activities:
        earliest_starts[vertex] = 0

    cost_until = 0

    processed_vertices = []
    for vertex in sorted_activities:
        if vertex not in processed_vertices:
            processed_vertices.append(vertex)
        for successor in graph.dictionary_out[vertex]:
            if successor not in processed_vertices:
                processed_vertices.append(successor)
                cost = graph.dictionary_cost[(vertex, successor)]
                for predecessor in graph.dictionary_in[successor]:
                    if predecessor in processed_vertices:
                        cost = min(cost, graph.dictionary_cost[(predecessor, successor)])
                costs[successor] = max(costs[successor], costs[vertex] + cost)
                cost_until += costs[successor]
                earliest_starts[successor] = cost_until

    return earliest_starts


def calculate_latest_starting_time(graph: TripleDictGraph):
    sorted_activities = topological_sort(graph)

    if sorted_activities is None:
        return None

    costs = {}
    for vertex in sorted_activities:
        costs[vertex] = 0

    earliest_starts = calculate_earliest_starting_time(graph)

    latest_starts = {}
    for vertex in sorted_activities:
        latest_starts[vertex] = float('inf')  # Initialize latest starting times as infinity

    cost_until = 0

    processed_vertices = []
    for vertex in reversed(sorted_activities):  # Reverse the order of iteration
        if vertex not in processed_vertices:
            processed_vertices.append(vertex)
        for predecessor in graph.dictionary_in[vertex]:  # Iterate over predecessors instead of successors
            if predecessor not in processed_vertices:
                processed_vertices.append(predecessor)
                cost = graph.dictionary_cost[(predecessor, vertex)]  # Use the predecessor-vertex cost
                for successor in graph.dictionary_out[predecessor]:
                    if successor in processed_vertices:
                        cost = min(cost, graph.dictionary_cost[(predecessor, successor)])
                costs[predecessor] = max(costs[predecessor], costs[vertex] + cost)
                cost_until += costs[predecessor]
                latest_starts[predecessor] = cost_until  # Store the latest starting time

    for vertex in latest_starts:
        if latest_starts[vertex] == float('inf'):
            latest_starts[vertex] = 0

    maximum_late_starting_time = max(latest_starts.values())
    for vertex in latest_starts:
        latest_starts[vertex] = max(maximum_late_starting_time - latest_starts[vertex], earliest_starts[vertex])

    return latest_starts


def find_critical_activities(graph):
    sorted_activities = topological_sort(graph)
    if sorted_activities is None:
        return None

    critical_activities = []
    earliest_starts = calculate_earliest_starting_time(graph)
    latest_start = reversed(calculate_latest_starting_time(graph))

    for activity in sorted_activities:
        if earliest_starts[activity] == latest_start[activity]:
            critical_activities.append(activity)

    if len(critical_activities) == 0:
        return None

    return critical_activities


"""is_DAG: This function checks whether the given graph is a Directed Acyclic Graph (DAG) using a depth-first search (DFS) approach. 
It detects cycles by maintaining a list of visited vertices and a stack. 
It recursively explores the predecessors of each node and checks for cycles by comparing vertices in the stack. 
If a cycle is found, it returns False; otherwise, it returns True.

topological_sort: This function performs a topological sort on the graph using a modified version of the predecessor counters algorithm. 
It initializes a queue with activities that have no predecessors and iteratively dequeues activities, updating the counts of their 
successors' predecessors. The sorted activities are stored in a list and returned. If a cycle is detected in the graph, it returns None.

calculate_earliest_starting_time: This function calculates the earliest starting time for each activity based on the topological sort order. It initializes a dictionary to store the earliest start times and processes each activity in the sorted order. For each successor, it considers the cost of the edge between the current activity and the successor and updates the earliest start time accordingly. The resulting earliest start times are returned.

calculate_latest_starting_time: This function calculates the latest starting time for each activity based on the topological sort order and the earliest start times. It initializes a dictionary to store the latest start times and iterates over the sorted activities in reverse order. For each activity, it determines the latest start time by considering its successors and their associated costs. The resulting latest start times are returned.

Overall, these functions work together to determine whether the graph is a DAG, perform a topological sort, calculate the earliest starting times, and calculate the latest starting times for the activities in the graph."""
