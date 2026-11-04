lst1 = [10,20,30,40]
temp = lst1[0]
lst1[0] = lst1[len(lst1)-1]
lst1[len(lst1)-1] = temp

print(lst1)