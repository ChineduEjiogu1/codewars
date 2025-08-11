def queue_time(customers, n):
    
    tills = [0] * n
    
    for customer in customers:
        min_till_index = tills.index(min(tills))
        tills[min_till_index] += customer
    
    return max(tills)
            