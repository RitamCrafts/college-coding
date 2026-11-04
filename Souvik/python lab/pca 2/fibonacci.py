def get_fibonacci(n):
    if(n == 0): return 0
    if(n == 1): return 1

    return get_fibonacci(n-1) + get_fibonacci(n-2)

n = int(input("Enter Limit: "))
for i in range(0,n):
    print(get_fibonacci(i),end=" ")


# using iteration

def get_fibonacci_iteration(n):
    a = 0
    b = 1
    for i in range(n):
        print(a,end=" ")
        c = a + b
        a = b
        b = c

num = int(input('Enter Number: '))
get_fibonacci_iteration(num)