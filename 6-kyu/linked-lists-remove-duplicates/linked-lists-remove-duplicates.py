class Node(object):
    def __init__(self, data):
        self.data = data
        self.next = None
​
def remove_duplicates(head):
    # Your code goes here.
    # Remember to return the head of the list.
    
    if head == None: return None
​
    previous = head
    current = previous.next
​
    while previous != None and current != None:
        if previous.data == current.data:
            previous.next = current.next
            current = previous.next
        elif previous.data != current.data:
            previous = current
            current = current.next
             
    return head