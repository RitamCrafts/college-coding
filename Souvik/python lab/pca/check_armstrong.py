
import math

def check_armstrong(n):
    temp = n
    sum = 0
    while(temp != 0):
        digit = temp % 10
        temp //= 10
        sum += math.pow(digit, 3)
    
    if(sum == n):
        print("Armstrong Number.")
    else:
        print("Not an Armstrong Number.")

n = int(input("Enter Number: "));
check_armstrong(n)