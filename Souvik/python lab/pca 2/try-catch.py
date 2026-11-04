import random

num = random.randint(1,100)

try:
    print('Number: ',num)
    if(num>5):
        print("Number is above 5.")
    else:
        raise ValueError("Number is Below 5")
    print("Number is Valid")
except ValueError as e:
    print(e)



    