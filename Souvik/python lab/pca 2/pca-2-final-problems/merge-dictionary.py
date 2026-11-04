# d1 = {"a":1,"b":2}
# d2 = {"c":4,"d":8}


# d1.update(d2)


# print(d1)


# manually


keys = []
values = []

d1 = {"a":1,"b":2}

d2 = {"c":4,"d":8}

for(key,value) in d1.items():
    keys.append(key)

for(key,value) in d2.items():
    keys.append(key)


for(key,value) in d1.items():
    values.append(value)

for(key,value) in d2.items():
    values.append(value)

d1.clear()

for i in range(len(keys)):
    d1[keys[i]] = values[i]
print(d1)