import copy


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
            graph.add_vertex(last_added+1)
            last_added += 1
    file_descriptor.close()

    return graph


def write_graph_to_file(graph, filename: str):
    file_descriptor = open(filename, 'wt')
    if len(graph.__dictionary_cost) == 0 and len(graph.__dictionary_in) == 0:
        raise Exception("There is nothing to write!!!")
    else:
        first_line = str(graph.number_of_vertices) + " " + str(graph.number_of_edges) + "\n"
        file_descriptor.write(first_line)
        for key in graph.__dictionary_cost.keys():
            line = ""
            line = str(key[0]) + " " + str(key[1]) + " " + str(graph.__dictionary_cost[key]) + "\n"
            file_descriptor.write(line)

        for vertex in graph.__dictionary_in.key():
            if len(graph.__dictionary_in[vertex]) == 0 and len(graph.__dictionary_out[vertex]) == 0:
                """
                here we have an isolated vertex
                """
                line = ""
                line = str(vertex) + "\n"
                file_descriptor.write(line)
    file_descriptor.close()


