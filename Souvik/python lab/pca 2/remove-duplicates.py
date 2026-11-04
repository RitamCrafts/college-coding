lst1 = [10,20,10,30]
count = 0

for i in lst1:
    for j in lst1:
        if i == j:
            count+=1

            if(count>1):
                lst1.remove(i)


print(lst1)

