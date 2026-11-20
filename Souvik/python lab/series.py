def get_fact(n):
    if(n == 0 or n == 1):
        return 1
    return n*get_fact(n-1)

n = int(input("Enter Limit: "))
sum = 0
for i in range(1,n):
    fact = get_fact(i)
    div_result = i/fact
    sum+=div_result
 

print(f"Result: {sum: .2f}")