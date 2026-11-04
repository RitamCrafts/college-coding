# class DivisionError(Exception):
#     pass


# def divide(a,b):
#     try:
#         if(b == 0):
#             raise DivisionError("b can't be 0")
#         return a/b
#     except ValueError as e:
#         print("Error: ",e)

# print(divide(5,4))
# print(divide(5,0))


class KeyError(Exception):
    pass

students={
    100:{"Name":"Souvik","Marks":100},
    101:{"Name":"Sumedha","Marks":80},
    102:{"Name":"Suman","Marks":60}
}

n = int(input("Enter Key: "))
if n not in students.keys():
    raise KeyError("Key doesn't exist")

print(f"Key Found, DATA: {students[n]}")