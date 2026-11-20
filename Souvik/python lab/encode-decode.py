s = input("Enter Message: ")
key = int(input('Enter Key: '))

def encdoe_message(s):
    result = ""
    for char in s:
        if(char.isupper()):
            result+= chr((ord(char)-ord('A')+key)%26+ord('A'))
        elif(char.islower()):
            result+=chr((ord(char)-ord('a')+key)%26+ord('a'))
        else:
            result+=char
    return result


print("Encoded: ",encdoe_message(s))