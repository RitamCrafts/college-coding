def display_database(students):
    print("Student Database")
    print("----------------")

    for roll_no, details in students.items():
        print("University Roll No:", roll_no)
        print("Student Name:", details["name"])
        print("Department:", details["department"])
        print("Email ID:", details["email"])
        print("----------------")


students = {
    101: {
        "name": "Rahul",
        "department": "Computer Science",
        "email": "rahul@gmail.com"
    },
    102: {
        "name": "Amit",
        "department": "Information Technology",
        "email": "amit@gmail.com"
    },
    103: {
        "name": "Priya",
        "department": "Electronics",
        "email": "priya@gmail.com"
    },
    104: {
        "name": "Sneha",
        "department": "Mechanical",
        "email": "sneha@gmail.com"
    }
}

display_database(students)