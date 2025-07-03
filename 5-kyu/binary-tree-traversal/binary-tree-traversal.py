# Pre-order traversal
def pre_order(node):
    
    if node == None:
        return []
    
    left_result = pre_order(node.left)
    right_result = pre_order(node.right)
    return [node.data] + left_result + right_result
    
# In-order traversal
def in_order(node):
    
    if node == None:
        return []
    
    left_result = in_order(node.left)
    right_result = in_order(node.right)
    return left_result + [node.data] + right_result
​
# Post-order traversal
def post_order(node):
    
    if node == None:
        return []
    
    left_result = post_order(node.left)
    right_result = post_order(node.right)
    return left_result + right_result + [node.data]
​
​