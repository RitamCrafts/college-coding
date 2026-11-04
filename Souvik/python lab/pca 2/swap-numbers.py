a = int(input("Enter first Number: "))
b = int(input("Enter second Number: "))

print("1. Swap using third variable")
print("2. Swap without third variable")

ch = int(input("Enter Your Choice: "))

match ch:
    case 1:
        print("Before Swapping: ",a,b)
        temp = a
        a = b
        b = temp
        print("After Swapping: ",a,b)
    case 2:
        print("Before Swapping: ",a,b)
        a = a+b
        b = a-b
        a = a-b
        print("After Swapping: ",a,b)

    case _:
        print("Invalid Choice")

