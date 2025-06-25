""" For your information:
class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None
"""
​
def sorted_insert(head, data):
    # Your code goes here.
    # Make sure to return the head of the list.
    
    new_node = Node(data)
    
    if head == None:
        return new_node
    
    if new_node.data < head.data:
        new_node.next = head
        return new_node
    
    current = head
    
    while (current.next != None) and not (new_node.data > current.data and new_node.data <= current.next.data):
        current = current.next
    temp = current.next 
    current.next = new_node
    new_node.next = temp
    
    return head