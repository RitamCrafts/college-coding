a = list(eval(input("Enter Numbers: ")))
n = int(input("Enter no: "))

found = False
for i in a:
    if(i == n):
        found = True
        break

if found == True:
    print("Element Found")
else:
    print("Not found")