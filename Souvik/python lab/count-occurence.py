list_one = [2,3,4,4,4,4,5,9,8,5,7,6,2,33,3,333,222,2,3,3,3]
count = 0
elem = int(input("Enter a element to count occurence: "));
for i in list_one:
    if elem == i:
        count+=1

if(count == 0):
    print("Not found")

print("Count: ",count)