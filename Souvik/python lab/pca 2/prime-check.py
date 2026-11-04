def check_prime(n):
    flag = True
    if(n <= 1):
        print("Neither prime nor composite")
        return
    for i in range(2,n):
        if(n%i == 0):
            flag = False
            break


    if(flag == True):
        print("The Number is Prime.")
    else:
        print("Not Prime")

n = int(input("Enter Number: "))
check_prime(n)