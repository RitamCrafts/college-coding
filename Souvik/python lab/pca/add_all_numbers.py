n = int(input("Enter Size of List: "))
listOne=[]
for i in range(0,n):
    ele = int(input('Enter Number: '))
    listOne.append(ele)

sum = 0
for i in listOne:
    sum += i
print("Sum: ",sum);