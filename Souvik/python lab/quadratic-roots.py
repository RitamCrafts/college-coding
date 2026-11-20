import math

a = int(input("Enter 1st coefficient: "))
b = int(input("Enter 2nd coefficient: "))
c = int(input("Enter 3rd coefficient: "))

def find_roots(a,b,c):
    discriminant = math.pow(b,2)-4*a*c
    if(discriminant>0):
        print("Roots are positive but not equal.")
        root1 = (-b+math.sqrt(discriminant))/2*a
        root2 = (-b-math.sqrt(discriminant))/2*a
        print(f"Roots Are: {root1:.2f},{root2:.2f}")
    elif(discriminant == 0):
        print("Roots are positive and equal.")
        root1 = (-b+math.sqrt(discriminant))/2*a
        print(f"Both Roots Are: {root1:.2f}")
    else:
        print("Roots are imaginary")
        real_part = -b/(2*a)
        imag_part = math.sqrt(abs(discriminant))/(2*a)
        
        print(f"Root1: {real_part:.2f} + {imag_part:.2f} i and Root2: {real_part:.2f} - {imag_part:.2f} i")

if a == 0:
    print("Coefficient of x² cannot be zero.")
else:
    find_roots(a, b, c)