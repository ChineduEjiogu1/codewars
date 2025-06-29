from math import floor, log
from collections import deque
​
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
​
def build_tree_from_inorder(a):
    if not a:
        return None
    
    if len(a) == 1:
        return TreeNode(a[0])
    
    n = len(a)
    h = floor(log(n, 2))
    left_size = (2**(h-1) - 1) + min((n - (2**h - 1)), 2**(h-1))
    
    root = TreeNode(a[left_size])
    root.left = build_tree_from_inorder(a[:left_size])
    root.right = build_tree_from_inorder(a[left_size + 1:])
    
    return root
​
def breadth_first_traversal(root):
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        node = queue.popleft()
        result.append(node.val)
        
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    
    return result
​
def complete_binary_tree(a):
    if not a:
        return []
    
    root = build_tree_from_inorder(a)
    return breadth_first_traversal(root)