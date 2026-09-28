import math

def get_roots(a,b,c):
    discriminant = math.pow(b,2)-4*a*c
    if discriminant > 0:
        r1 = (-b+math.sqrt(discriminant))/2*a
        r2 = (-b-math.sqrt(discriminant))/2*a
        print("Roots are real and different.")
        print("Root 1: ",r1)
        print("Root 2: ",r2)
    elif discriminant == 0:
        r1 = -b/(2*a)
        print("Roots are real and same.")
        print("Root 1: ",r1)
    else:
        realPart = -b/2*a
        imaginaryPart = math.sqrt(-discriminant)/2*a
        print("Roots are complex and different.")
        print("Root 1: ",realPart,"+",imaginaryPart,"i")
        print("Root 2: ",realPart,"-",imaginaryPart,"i");

a = float(input("Enter coefficient a: "))
b = float(input("Enter coefficient b: "))
c = float(input("Enter coefficient c: "))
get_roots(a,b,c)