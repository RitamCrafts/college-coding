def check_username():
    username = input("Enter Username: ")
    if not username.isalnum():
        print("Invalid Username")
    else:
        print('valid Username')


def check_valid_pan():
    pan = input("Enter PAN No: ")
    if len(pan) != 10:
        print("Invalid Pan No")
    elif not (pan[0:5].isupper() and pan[0:5].isalpha()):
        print("Invalid Pan No")
    elif not pan[5:9].isdigit():
        print("Invalid Pan No")
    elif not (pan[9].isupper() and pan[9].isalpha()):
        print("Invalid Pan No")
    else:
        print("Valid Pan No")

check_username()
check_valid_pan()