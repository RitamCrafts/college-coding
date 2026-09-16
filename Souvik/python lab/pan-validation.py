pan = input("Enter PAN No: ").strip().upper()

if len(pan) != 10:
    print("Invalid PAN length. PAN must be 10 characters long.")
elif not pan[0:5].isalpha():
    print("Invalid PAN format. PAN must contain only letters. in 0 to 5 places")
elif not pan[5:9].isdigit():
    print("Invalid PAN format. PAN must contain digits in positions 5 to 9.")
elif not pan[9].isalpha():
    print("Invalid PAN format. PAN must contain a letter in position 9.")
else:
    print("Valid PAN number.")