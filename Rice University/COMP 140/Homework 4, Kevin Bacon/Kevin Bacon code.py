"""
The Kevin Bacon Game.

Replace "pass" with your code.
"""

import simpleplot
import comp140_module4 as movies
from collections import defaultdict

class Queue:
    """
    A simple implementation of a FIFO queue.
    """

    def __init__(self):
        """
        Initialize the queue.
        """
        self._queue = []

    def __len__(self):
        """
        Returns: an integer representing the number of items in the queue.
        """
        return len(self._queue)

    def __str__(self):
        """
        Returns: a string representation of the queue.
        """
        string_rep = "Queue:\n"
        for element in self._queue:
            string_rep += "\t" + element + "\n"
        return string_rep

    def push(self, item):
        """
        Add item to the queue.

        input:
            - item: any data type that's valid in a list
        """
        self._queue.insert(0, item)

    def pop(self):
        """
        Remove the least recently added item.

        Assumes that there is at least one element in the queue.  It
        is an error if there is not.  You do not need to check for
        this condition.

        Returns: the least recently added item.
        """
        return self._queue.pop()

    def clear(self):
        """
        Remove all items from the queue.
        """
        self._queue = []


def bfs(graph, start_node):
    """
    Performs a breadth-first search on graph starting at the
    start_node.

    inputs:
        - graph: a graph object
        - start_node: a node in graph representing the start node

    Returns: a two-element tuple containing a dictionary
    associating each visited node with the order in which it
    was visited and a dictionary associating each visited node
    with its parent node.
    """
    node_queue = Queue()
    dist = {}
    parent = {}
    for node in graph.nodes():
        dist[node] = float("inf")
        parent[node] = None
    dist[start_node] = 0
    node_queue.push(start_node)
    while len(node_queue) != 0:
        node = node_queue.pop()
        for neighbor in graph.get_neighbors(node):
            if dist[neighbor] == float("inf"):
                dist[neighbor] = dist[node] + 1
                parent[neighbor] = node
                node_queue.push(neighbor)
    return dist, parent

def distance_histogram(graph, node):
    """
    Computes the distance between the given node and all other
    nodes in that graph and creates a histogram of those distances.

    inputs:
        - graph: a graph object
        - node: a node in graph

    returns: a dictionary mapping each distance with the number of
    nodes that are that distance from node.
    """
    histogram = defaultdict(int)
    bfs_tuple = bfs(graph, node)
    for value in bfs_tuple[0].values():
        histogram[value] += 1
    return dict(histogram)

def find_path(graph, start_person, end_person, parents):
    """
    Computes the path from start_person to end_person in the graph.

    inputs:
        - graph: a graph oject with edges representing the connections between people
        - start_person: a node in graph representing the starting node
        - end_person: a node in graph representing the ending node
        - parents: a dictionary representing the parents in the graph

    returns a list of tuples of the path in the form:
        [(actor1, {movie1a, ...}), (actor2, {movie2a, ...}), ...]
    """
    path = []
    current_node = end_person
    previous_node = end_person
    edge = set()
    start_to_end = False
    while current_node != None:
        if current_node != previous_node:
            edge = graph.get_attrs(current_node, previous_node)
        path.insert(0, (current_node, edge))
        previous_node = current_node
        current_node = parents[current_node]
    #checking to see if a path from start_person to end_person was found
    for node, edge in path:
        if start_person == node:
            start_to_end = True
    if not start_to_end:
        path = []
    return path


def play_kevin_bacon_game(graph, start_person, end_people):
    """
    Play the "Kevin Bacon Game" on the actors in the given
    graph.

    inputs:
        - graph: a a graph oject with edges representing the connections between people
        - start_person: a node in graph representing the node from which the search will start
        - end_people: a list of nodes in graph to which the search will be performed

    Prints the results out.
    """
    bfs_tuple = bfs(graph, start_person)
    for actor in end_people:
        path = find_path(graph, start_person, actor, bfs_tuple[1]) 
        movies.print_path(path)
        
        
def run():
    """
    Load a graph and play the Kevin Bacon Game.
    """
    graph5000 = movies.load_graph('subgraph5000')

    if len(graph5000.nodes()) > 0:
        # You can/should use smaller graphs and other actors while
        # developing and testing your code.
        play_kevin_bacon_game(graph5000, 'Kevin Bacon',
            ['Amy Adams', 'Andrew Garfield', 'Anne Hathaway', 'Barack Obama', \
             'Benedict Cumberbatch', 'Chris Pine', 'Daniel Radcliffe', \
             'Jennifer Aniston', 'Joseph Gordon-Levitt', 'Morgan Freeman', \
             'Sandra Bullock', 'Tina Fey'])

        # Plot distance histograms
        for person in ['Kevin Bacon', 'Stephanie Fratus']:
            hist = distance_histogram(graph5000, person)
            simpleplot.plot_bars(person, 400, 300, 'Distance', \
                'Frequency', [hist], ["distance frequency"])

# Uncomment the call to run below when you have completed your code.

# run()
