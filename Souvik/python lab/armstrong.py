import math

def check_armstrong(n):
    temp = n
    sumResult = 0
    while(temp != 0):
        lastDigit = temp%10
        temp //= 10
        sumResult+=math.pow(lastDigit,3)

    if(sumResult == n):
        print("Armstrong")
    else:
        print("Not Armstrong")

check_armstrong(153)
check_armstrong(101)

    

