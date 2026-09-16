def cel_to_fer(cel_temp):
    fer_temp = (9 * cel_temp) / 5 + 32
    print('Fahrenheit:', fer_temp)


def fer_to_cel(fer_temp):
    cel_temp = (5 * (fer_temp - 32)) / 9
    print('Celsius:', cel_temp)


fer_temp = float(input('Enter Fahrenheit temp: '))
cel_temp = float(input('Enter Celsius temp: '))

cel_to_fer(cel_temp)
fer_to_cel(fer_temp)