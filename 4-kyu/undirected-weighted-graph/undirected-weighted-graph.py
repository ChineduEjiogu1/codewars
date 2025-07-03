class Graph():
    """
    A class to represent an undirected weighted graph and provide conversions
    between different graph representations (dictionary, adjacency matrix, adjacency list).
    Also includes functionality to find all paths between two vertices.
    """

    def __init__(self, vertices_num):
        """
        Initialize a Graph object.
        
        Args:
            vertices_num (int): Number of vertices in the graph (nodes named A0 to A(n-1))
        """
        # number of nodes (an integer)
        self.v = vertices_num
        # (maybe not useful here) : list of nodes from "A0", "A1" ... to "A index (vertices_num - 1)"
        self.nodes = None
        
    def dfs_helper(self, current_node, graph, end_vertex, current_path, results):
        """
        Recursive helper function for finding all paths using depth-first search.
        
        Args:
            current_node (str): Current node being visited (e.g., "A0")
            graph (dict): Graph in dictionary format
            end_vertex (str): Target node to reach
            current_path (list): Current path being built
            results (list): List to accumulate all found path strings
        """
        # Base case: if we've reached the target vertex
        if current_node == end_vertex:
            # Convert current path to string format and add to results
            path_string = "-".join(current_path)
            results.append(path_string)
            return
        
        # Recursive case: explore all neighbors
        for neighbor_node, weight in graph[current_node]:
            # Cycle detection: only visit nodes not already in current path
            if neighbor_node not in current_path:
                # Add neighbor to path and explore recursively
                current_path.append(neighbor_node)
                self.dfs_helper(neighbor_node, graph, end_vertex, current_path, results)
                # Backtrack: remove neighbor from path after exploring
                current_path.pop()

    # from adjacency matrix to dictionary
    def adjmat_2_graph(self, adjm):
        """
        Convert adjacency matrix to graph dictionary format.
        
        Args:
            adjm (list of lists): 2D matrix where adjm[i][j] is weight from node i to j (0 = no edge)
            
        Returns:
            dict: Graph in format {'A0': [('A3', 1), ('A5', 4)], ...}
        """
        result_dict = {}
        
        # Scan entire matrix for non-zero values (edges)
        for i in range(self.v):
            for j in range(self.v):
                if adjm[i][j] != 0:
                    # Convert matrix indices to node names
                    source_node_name = "A" + str(i)
                    neighbor_node_name = "A" + str(j)
                    weight = adjm[i][j]
                    # Add neighbor to source node's adjacency list
                    result_dict.setdefault(source_node_name, []).append((neighbor_node_name, weight))

        # Sort each node's neighbor list to maintain required ordering
        for node_name in result_dict:
            result_dict[node_name].sort()

        return result_dict
            
    # from dictionary to adjacency matrix
    def graph_2_mat(self, graph):
        """
        Convert graph dictionary to adjacency matrix format.
        
        Args:
            graph (dict): Graph in format {'A0': [('A3', 1), ('A5', 4)], ...}
            
        Returns:
            list of lists: 2D matrix where matrix[i][j] is weight from node i to j
        """
        # Initialize matrix with zeros (no edges)
        matrix = [[0 for _ in range(self.v)] for _ in range(self.v)]

        # Process each node and its neighbors
        for node_name, neighbors_list in graph.items():
            # Convert node name to matrix index
            source_index = int(node_name[1:])

            # Set matrix values for each neighbor
            for neighbor_name, weight in neighbors_list:
                neighbor_index = int(neighbor_name[1:])
                matrix[source_index][neighbor_index] = weight

        return matrix
    
    # from dictionary to adjacency list    
    def graph_2_list(self, graph):
        """
        Convert graph dictionary to adjacency list format.
        
        Args:
            graph (dict): Graph in format {'A0': [('A3', 1), ('A5', 4)], ...}
            
        Returns:
            list: Adjacency list in format [['A0', [('A3', 1), ('A5', 4)]], ...]
        """
        result_list = []

        # Convert each dictionary entry to [node_name, neighbors_list] format
        for node_name, neighbors_list in graph.items():
            result_list.append([node_name, neighbors_list])
    
        # Sort by node names (A0, A1, A2, etc.)
        result_list = sorted(result_list)
        return result_list
                
    # from adjacency list to dictionary
    def list_2_graph(self, lst):
        """
        Convert adjacency list to graph dictionary format.
        
        Args:
            lst (list): Adjacency list in format [['A0', [('A3', 1), ('A5', 4)]], ...]
            
        Returns:
            dict: Graph in format {'A0': [('A3', 1), ('A5', 4)], ...}
        """
        result_dict = {}
    
        # Convert each [node_name, neighbors_list] entry to dictionary key-value pair
        for node_name, neighbors_list in lst:
            result_dict[node_name] = neighbors_list
    
        return result_dict
            
    # from adjacency matrix to adjacency list    
    def mat_2_list(self, mat):
        """
        Convert adjacency matrix to adjacency list format.
        
        Args:
            mat (list of lists): 2D matrix where mat[i][j] is weight from node i to j
            
        Returns:
            list: Adjacency list in format [['A0', [('A3', 1), ('A5', 4)]], ...]
        """
        result_list = []

        # Process each row (node) in the matrix
        for i in range(self.v):
            # Convert matrix index to node name
            node_name = "A" + str(i)
            neighbors_list = []

            # Scan row for non-zero values (neighbors)
            for j in range(self.v):
                if mat[i][j] != 0:
                    neighbor_name = "A" + str(j)
                    weight = mat[i][j]
                    neighbors_list.append((neighbor_name, weight))

            # Sort neighbors and add to result
            neighbors_list.sort()
            result_list.append([node_name, neighbors_list])

        return result_list
    
    # from adjacency list to adjacency matrix
    def list_2_mat(self, lst):
        """
        Convert adjacency list to adjacency matrix format.
        
        Args:
            lst (list): Adjacency list in format [['A0', [('A3', 1), ('A5', 4)]], ...]
            
        Returns:
            list of lists: 2D matrix where matrix[i][j] is weight from node i to j
        """
        # Initialize matrix with zeros (no edges)
        matrix = [[0 for _ in range(self.v)] for _ in range(self.v)]

        # Process each node and its neighbors
        for node_name, neighbors_list in lst:
            # Convert node name to matrix index
            source_index = int(node_name[1:])

            # Set matrix values for each neighbor
            for neighbor_name, weight in neighbors_list:
                neighbor_index = int(neighbor_name[1:])
                matrix[source_index][neighbor_index] = weight

        return matrix
                 
    # find all path from node start_vertex to node end_vertex
    def find_all_paths(self, graph, start_vertex, end_vertex):
        """
        Find all possible paths from start_vertex to end_vertex using DFS.
        
        Args:
            graph (dict): Graph in dictionary format
            start_vertex (str): Starting node (e.g., "A0")
            end_vertex (str): Target node (e.g., "A4")
            
        Returns:
            list: All paths as strings, sorted by length then alphabetically
                  (e.g., ['A0-A2-A4', 'A0-A3-A2-A4'])
        """
        result_list = []
        # Initialize path with starting vertex
        current_path = [start_vertex]
        
        # Use recursive DFS to find all paths
        self.dfs_helper(start_vertex, graph, end_vertex, current_path, result_list)
        
        # Sort results: first by length, then alphabetically
        result_list = sorted(sorted(result_list, key=str), key=len)
        
        return result_list
