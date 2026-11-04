s = input('Enter a string: ')
freq = {}

for char in s:
    if(char in freq):
        freq[char]+=1
    else:
        freq[char] = 1

print(f"Freq: {freq}")

