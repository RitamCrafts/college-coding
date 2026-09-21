# Program to perform different operations on a list

numbers = [10, 25, -5, 40, 15, 8, -10]

print("Original list:", numbers)

# 1. Insert a new number at the end
numbers.append(50)
print("After inserting at end:", numbers)

# 2. Insert a number at a given index
numbers.insert(2, 30)
print("After inserting 30 at index 2:", numbers)

# 3. Delete a number from the list
numbers.remove(-5)
print("After deleting -5:", numbers)

# 4. Display all even numbers
even_numbers = []

for num in numbers:
    if num % 2 == 0:
        even_numbers.append(num)

print("Even numbers:", even_numbers)

# 5. Calculate sum and average
total = sum(numbers)
average = total / len(numbers)

print("Sum of numbers:", total)
print("Average of numbers:", average)

# 6. Find maximum and minimum
print("Maximum number:", max(numbers))
print("Minimum number:", min(numbers))

# 7. Find average of even numbers only
even_sum = 0
even_count = 0

for num in numbers:
    if num % 2 == 0:
        even_sum = even_sum + num
        even_count = even_count + 1

if even_count > 0:
    even_average = even_sum / even_count
    print("Average of even numbers:", even_average)
else:
    print("No even numbers in the list")

# 8. Find average of positive numbers only
positive_sum = 0
positive_count = 0

for num in numbers:
    if num > 0:
        positive_sum = positive_sum + num
        positive_count = positive_count + 1

if positive_count > 0:
    positive_average = positive_sum / positive_count
    print("Average of positive numbers:", positive_average)
else:
    print("No positive numbers in the list")