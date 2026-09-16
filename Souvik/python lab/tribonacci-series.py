def tribonacci(n):
    if(n == 0):
        return 0
    elif(n == 1 or n == 2):
        return 1

    return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3)

start = int(input("Enter Start: "))
end = int(input("Enter End: "))


for i in range(start,end):
    print(tribonacci(i))