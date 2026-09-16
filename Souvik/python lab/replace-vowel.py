input_str = input("Enter a String: ")
vowel = "aeiouAEIOU"
result = ""

for i in input_str:
    if i not in vowel:
        result += i

print("String after removed vowels: ",result);