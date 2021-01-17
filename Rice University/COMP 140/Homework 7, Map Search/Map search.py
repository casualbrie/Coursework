"""
Map Search
"""

import comp140_module7 as maps

class Queue:
    """
    A simple implementation of a FIFO queue.
    """

    def __init__(self):
        """
        Initialize the queue.
        """
        self._items = []

    def __len__(self):
        """
        Returns: an integer representing the number of items in the queue.
        """
        return len(self._items)

    def __str__(self):
        """
        Returns: a string representation of the queue.
        """
        return str(self._items)

    def push(self, item):
        """
        Add item to the queue.

        input:
            - item: any data type that's valid in a list
        """
        self._items.append(item)

    def pop(self):
        """
        Remove the least recently added item.

        Assumes that there is at least one element in the queue.  It
        is an error if there is not.  You do not need to check for
        this condition.

        Returns: the least recently added item.
        """
        return self._items.pop(0)

    def clear(self):
        """
        Remove all items from the queue.
        """
        self._items = []


class Stack:
    """
    A simple implementation of a LIFO stack.
    """
    def __init__(self):
        """
        Initialize the queue.
        """
        self._items = []

    def __len__(self):
        """
        Returns: an integer representing the number of items in the queue.
        """
        return len(self._items)

    def __str__(self):
        """
        Returns: a string representation of the queue.
        """
        return str(self._items)

    def push(self, item):
        """
        Add item to the queue.

        input:
            - item: any data type that's valid in a list
        """
        self._items.append(item)

    def pop(self):
        """
        Remove the least recently added item.

        Assumes that there is at least one element in the queue.  It
        is an error if there is not.  You do not need to check for
        this condition.

        Returns: the least recently added item.
        """
        return self._items.pop()

    def clear(self):
        """
        Remove all items from the queue.
        """
        self._items = []


def bfs_dfs(graph, rac_class, start_node, end_node):
    """
    Performs a breadth-first search or a depth-first search on graph
    starting at the start_node.  The rac_class should either be a
    Queue class or a Stack class to select BFS or DFS.

    Completes when end_node is found or entire graph has been
    searched.

    inputs:
        - graph: a directed Graph object representing a street map
        - rac_class: a restricted access container (Queue or Stack) class to
          use for the search
        - start_node: a node in graph representing the start
        - end_node: a node in graph representing the end

    Returns: a dictionary associating each visited node with its parent
    node.
    """
    dist = {}
    parent = {}

    for node in graph.nodes():
        dist[node] = float('inf')
        parent[node] = None

    dist[start_node] = 0
    #Breadth first search
    if rac_class == Queue:
        queue = Queue()
        queue.push(start_node)
        while queue:
            node = queue.pop()
            nbrs = graph.get_neighbors(node)
            for nbr in nbrs:
                if dist[nbr] == float('inf'):
                    dist[nbr] = dist[node] + 1
                    parent[nbr] = node
                    queue.push(nbr)
                #ending upon giving end_node a parent
                if nbr == end_node:
                    queue.clear()
                    break
    #Depth first search
    if rac_class == Stack:
        stack = Stack()
        stack.push(start_node)
        while stack:
            node = stack.pop()
            nbrs = graph.get_neighbors(node)
            for nbr in nbrs:
                if dist[nbr] == float('inf'):
                    dist[nbr] = dist[node] + 1
                    parent[nbr] = node
                    stack.push(nbr)
                #ending upon giving end_node a parent
                if nbr == end_node:
                    stack.clear()
                    break
    return parent

#print(bfs_dfs(maps.load_test_graph('line'), Queue, 'A', 'E'))

def dfs(graph, start_node, end_node, parent):
    """
    Performs a recursive depth-first search on graph starting at the
    start_node.

    Completes when end_node is found or entire graph has been
    searched.

    inputs:
        - graph: a directed Graph object representing a street map
        - start_node: a node in graph representing the start
        - end_node: a node in graph representing the end
        - parent: a dictionary that initially has one entry associating
                  the original start_node with None

    Returns: the modified parent dictionary which maps each visited node
    to its parent node
    """
    for nbr in graph.get_neighbors(start_node):
        #base case
        if start_node == end_node:
            return
        #recursive case
        if nbr not in parent:
            parent[nbr] = start_node
            dfs(graph, nbr, end_node, parent)
    return


def astar(graph, start_node, end_node,
          edge_distance, straight_line_distance):
    """
    Performs an A* search on graph starting at start_node.

    Completes when end_node is found or entire graph has been
    searched.

    inputs:
        - graph: a directed Graph object representing a street map
        - start_node: a node in graph representing the start
        - end_node: a node in graph representing the end
        - edge_distance: a function which takes two nodes and a graph
                         and returns the actual distance between two
                         neighboring nodes
        - straight_line_distance: a function which takes two nodes and
                         a graph and returns the straight line distance 
                         between two nodes

    Returns: a dictionary associating each visited node with its parent
    node.
    """
    parent = {}
    openset = {}
    closedset = {}
    parent[start_node] = None
    openset[start_node] = 0
    while openset:
        #finding the node with the lowest f cost in openset
        lowest_value = 9999999
        for key, value in openset.items():
            if value + straight_line_distance(key, end_node, graph) < lowest_value:
                current_node = key
                lowest_value = value
        #if the node with the lowest f cost is the end node, we're done
        if current_node == end_node:
            return parent
        else:
            #removing the chosen node from the openset to the closed set
            closedset[current_node] = openset.pop(current_node)
            for nbr in graph.get_neighbors(current_node):
                distance = edge_distance(current_node, nbr, graph)
                #if the neighbor hasn't been explored yet, adding it to openset
                if (nbr not in openset) and (nbr not in closedset):
                    openset[nbr] = closedset[current_node] + distance
                    parent[nbr] = current_node
                #if the neighbor has been explored and a better path has been found,
                #	changing the parent of the neighbor and correcting g cost
                elif nbr in openset:
                    #checking to see if nbr is in openset first to avoid key errors
                    if openset[nbr] > closedset[current_node] + distance:
                        openset[nbr] = closedset[current_node] + distance
                        parent[nbr] = current_node
    return parent


# You can replace functions/classes you have not yet implemented with
# None in the call to "maps.start" below and the other elements will
# work.

maps.start(bfs_dfs, Queue, Stack, dfs, astar)
