                    weight = mat[i][j]
                    neighbors_list.append((neighbor_name, weight))
​
            # Sort neighbors and add to result
            neighbors_list.sort()
            result_list.append([node_name, neighbors_list])
​
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
​
        # Process each node and its neighbors
        for node_name, neighbors_list in lst:
            # Convert node name to matrix index
            source_index = int(node_name[1:])
​
            # Set matrix values for each neighbor
            for neighbor_name, weight in neighbors_list:
                neighbor_index = int(neighbor_name[1:])
                matrix[source_index][neighbor_index] = weight
​
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