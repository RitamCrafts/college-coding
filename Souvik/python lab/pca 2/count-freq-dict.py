lst1 = [1,2,2,3,4,4,5]
freq={}

for i in lst1:
    if i in freq:
        freq[i]+=1
    else:
        freq[i] = 1

print("Freq: ",freq)