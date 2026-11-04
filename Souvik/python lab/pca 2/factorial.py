def count_factorial(n):
    if(n == 0 or n == 1):
        return 1
    return n*count_factorial(n-1)


n = int(input('Enter a Number: '))
print(f"Factorial of Number {n} is {count_factorial(n)}")