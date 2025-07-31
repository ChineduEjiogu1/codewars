def ip_to_integer(ip_address_string):
    
    octets = [int(octet) for octet in ip_address_string.split('.')]  # Split and convert to integers
    
    ip_as_integer = 0
    # Loop through octets with their corresponding powers of 256
    for i, octet in enumerate(octets):
        ip_as_integer += octet * (256 ** (3 - i)) # Apply power based on position
        
    return ip_as_integer
​
def ips_between(start, end):
    # TODO
    
    return  ip_to_integer(end) - ip_to_integer(start)