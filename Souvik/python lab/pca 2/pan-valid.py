pan = input("Enter PAN Number: ")


def check_valid_pan(pan):
    if(len(pan)!= 10):
        print("Invalid PAN")
    elif(not pan[0:5].isalpha()):
        print("Invalid PAN")
    elif (not pan[5:9].isdigit()):
        print('Invalid PAN')
    elif(not pan[9].isalpha()):
        print("Invalid PAN")
    else:
        print("Valid PAN")

check_valid_pan(pan)


