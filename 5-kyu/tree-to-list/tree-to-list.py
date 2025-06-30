from collections import deque
​
class Node:
    def __init__(self, data, child_nodes=None):
        self.data = data
        self.child_nodes = [] if child_nodes is None else child_nodes
​
def tree_to_list(tree_root):
    result_list = []
    
    if not tree_root:
        return []
    
    queue = deque()
    queue.append(tree_root)
    
    while queue:
        node = queue.popleft()
        result_list.append(node.data)
        for child in node.child_nodes:
            queue.append(child)
    
    return result_list
    
    