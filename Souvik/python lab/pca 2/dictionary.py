students = {
    101:{
        "name":"Souvik",
        "age":22,
        "gender":"Male",
    },
    102:{
        "name":"Sourav",
        "age":23,
        "gender":"Male",
    },
    103:{
        "name":"Souradip",
        "age":21,
        "gender":"Male",
    },
}

def display_database(data):
    for (key,value) in data.items():
        print("Roll: ",key)
        print("Name: ",value["name"])
        print("Age: ",value["age"])
        print("Gender: ",value["gender"])

        print("---------------")


students[104]={
    "name":"Sumedha",
    "age":"20",
    "gender":"female"
}

students[104]["name"] = "Sayan"
display_database(students)