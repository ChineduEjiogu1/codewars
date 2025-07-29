def rot13(message):
    #your code here
    
    encrypted_text = ""
    
    for char in range(len(message)):
        if 'a' <= message[char] <= 'z':
            rot_13 = (ord(message[char]) - ord('a') + 13) % 26
            encrypted_text += chr(rot_13 + ord('a'))
        elif 'A' <= message[char] <= 'Z':
            rot_13 = (ord(message[char]) - ord('A') + 13) % 26
            encrypted_text += chr(rot_13 + ord('A'))
        else:
            encrypted_text += message[char]
            
    return encrypted_text