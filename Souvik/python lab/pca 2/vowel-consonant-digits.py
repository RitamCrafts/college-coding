s = input("Enter a string: ").lower()
vowel = {'a','e','i','o','u'}
consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'}

digits = {'0','1','2','3','4','5','6','7','8','9'}

vowel_count = 0
consonant_count = 0
digit_count = 0

for i in s:
    if i in vowel:
        vowel_count+=1
    elif i in consonants:
        consonant_count+=1
    elif i in digits:
        digit_count+=1

print(f"Vowels: {vowel_count} Consonants: {consonant_count} Digit: {digit_count}")