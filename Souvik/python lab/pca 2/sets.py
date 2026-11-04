# union

set1 = {10,20,30,4050}
set2 = {100,30,20}

print('Union: ',set1.union(set2))
print('Intersection: ',set1.intersection(set2))

print('Difference: ',set1.difference(set2))
print('symmetric difference: ',set1.symmetric_difference(set2))

# without biultin functions

set3 = set()

for i in set1:
    set3.add(i)

for i in set2:
    set3.add(i)

print('Union Manula: ',set3)

set3.clear()

duplicate = False
for i in set1:
    for j in set2:
        if(i == j):
            duplicate = True
            break

    if(duplicate == True):
        set3.add(i)

print('Intersection manual: ',set3)



set1 = {10, 20, 30, 40}
set2 = {30, 40, 50}

set3 = set1.copy()

for i in set1:
    duplicate = False

    for j in set2:
        if i == j:
            duplicate = True
            break

    if duplicate == True:
        set3.remove(i)

print("Difference Manual:", set3)