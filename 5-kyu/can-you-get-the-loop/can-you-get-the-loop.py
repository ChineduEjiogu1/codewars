def loop_size(node):
    slow_pointer = node
    fast_pointer = node.next
    
    while fast_pointer != slow_pointer and fast_pointer != None and fast_pointer.next != None:
        slow_pointer = slow_pointer.next
        fast_pointer = fast_pointer.next.next 
    
    counter = 0
    
    fast_pointer = fast_pointer.next
    counter += 1
​
    while fast_pointer != slow_pointer:
        fast_pointer = fast_pointer.next
        counter += 1
    
    return counter