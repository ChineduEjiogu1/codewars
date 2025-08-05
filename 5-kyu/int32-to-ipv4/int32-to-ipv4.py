def int32_to_ip(int32):
    # your code here
    
    octet1 = int32 // (256**3)
    remaining = int32 % (256**3)
​
    # Extract the second octet
    octet2 = remaining // (256**2)
    remaining = remaining % (256**2)
​
    # Extract the third octet
    octet3 = remaining // 256
    octet4 = remaining % 256
    
    ipv4_string = str(octet1) + "." + str(octet2) + "." + str(octet3) + "." + str(octet4)
    
    return ipv4_string