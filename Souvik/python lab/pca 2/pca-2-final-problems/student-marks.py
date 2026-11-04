students = {
    100:{
        "Name":"Souvik",
        "Marks":100,
        "Gender":"Male"
    },
    101:{
        "Name":"Suman",
        "Marks":90,
        "Gender":"Male"
    },
    102:{
        "Name":"Sourav",
        "Marks":80,
        "Gender":"Male"
    },
    103:{
        "Name":"Sumedha",
        "Marks":70,
        "Gender":"Female"
    },
    104:{
        "Name":"Surbhi",
        "Marks":60,
        "Gender":"Female"
    }
}

def display_dict(data):
    for(key,values) in data.items():
        print("Roll No: ",key)
        print("Name: ",values["Name"])
        print("----------")


display_dict(students)


lst1 = list()
def get_topper(data):
    highest = 0
    topper = ""
    for(key,values) in data.items():
        if(values["Marks"]>highest):
            highest = values["Marks"]
            topper = values["Name"]

    print(f"Topper: {topper} , Marks: {highest}")

get_topper(students)