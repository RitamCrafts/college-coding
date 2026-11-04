s = input("Enter a string: ")
ch = input("Enter character: ")

result = ""
for i in s:
    if i != ch:
        result+=i

print("Modified string: ",result)