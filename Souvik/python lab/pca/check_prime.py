def check_prime(n):
    if n<= 1:
        print('Neither prime nor composite Number.')
        return
    else:
        for i in range(2,n):
            if(n%i == 0):
                print("Not a prime no.")
                break

            else:
                print('prime no')
                break

n = int(input('enter a no: '))
check_prime(n)