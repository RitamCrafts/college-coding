students={
    101:{
        "name":"Souvik",
        "Marks":600
    },
    102:{
        "name":"Sumedha",
        "Marks":500
    },
    103:{
        "name":"Rahul",
        "Marks":400
    },
}

lst1 = list()



def append_marks(data):
    for(key,value) in data.items():
        lst1.append(value["Marks"])


append_marks(students)
lst1.sort()

print("Highest Marks: ",lst1[len(lst1)-1])