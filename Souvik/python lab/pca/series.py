def get_fact(n):
    if(n == 0 or n == 1):
        return 1

    return n*get_fact(n-1)

def get_series(n):
    sum = 0.0
    for i in range(1,n+1):
        sum += i/get_fact(i)

    print("Sum is: ",sum)

n = int(input("Enter Number of terms: "))
get_series(n)