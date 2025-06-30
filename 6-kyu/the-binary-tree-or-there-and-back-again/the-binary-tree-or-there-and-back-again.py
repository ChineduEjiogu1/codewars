def rotate_left(tree):
    if tree.right == None:
        return tree
    else:
        new_position = tree.right
        tree.right = new_position.left
        new_position.left = tree
    return new_position
​
def rotate_right(tree):
    if tree.left == None:
        return tree
    else:
        new_position = tree.left
        tree.left = new_position.right  
        new_position.right = tree
    return new_position