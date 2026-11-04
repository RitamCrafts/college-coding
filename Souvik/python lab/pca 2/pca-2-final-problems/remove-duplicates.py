n = int(input("Enter Size: "))
lst1 = list()

for i in range(n):
    val = int(input(f"Enter Number {i+1}: "))
    lst1.append(val)

print("Before removing duplicates: ",lst1)

freq = {}

for i in lst1:
    if i in freq:
        freq[i]+=1
    else:
        freq[i] = 1

print(freq)
trying = 1
for(key,value) in freq.items():
    if(value>1):
        while(trying<value):
            lst1.remove(key)
            trying+=1
        trying = 1
        

print("After Removing Duplicates: ",lst1)