from preloaded import Node
​
# Node is defined in preloaded:
# class Node:
#     def __init__(self, data):
#        self.data = data
#        self.next = None
​
def length(node: Node) -> int:
    counter = 0
    
    while node != None:
        node = node.next
        counter += 1
        
    return counter
  
def count(node: Node, data) -> int:
    counter = 0
    
    while node != None:
        if node.data == data:
            counter += 1
        node = node.next
    
    return counter