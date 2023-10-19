import random

# Ask user for a number
number = int(input("Enter a number: "))

# Create an array of random integers from -100 to 100
array = [random.randint(-100, 100) for _ in range(10)]

# Initialize variables
sum = 0
product = 1
min_value = float('inf')
min_indexes = []
max_value = float('-inf')
max_indexes = []
guess_indexes = []
guess_count = 0

# Collect data while initializing
for i, num in enumerate(array):
    sum += num
    product *= num
    
    if num < min_value:
        min_value = num
        min_indexes = [i]
    elif num == min_value:
        min_indexes.append(i)
    
    if num > max_value:
        max_value = num
        max_indexes = [i]
    elif num == max_value:
        max_indexes.append(i)
    
    if num == number:
        guess_indexes.append(i)
        guess_count += 1

# Print the array
print("Array:", array)

# Print the properties
print("Sum:", sum)
print("Product:", product)
print("Minimum Value:", min_value)
print("Minimum Indexes:", min_indexes)
print("Maximum Value:", max_value)
print("Maximum Indexes:", max_indexes)
print("Number", number, "Presence:")
print("Indexes:", guess_indexes)
print("Count:", guess_count)

# Calculate mean and geometric mean
mean = sum / len(array)
geometric_mean = product ** (1 / len(array))

# Print mean and geometric mean
print("Mean:", mean)
print("Geometric Mean:", geometric_mean)

# Sort the array using insertion sort
for i in range(1, len(array)):
    key = array[i]
    j = i - 1
    while j >= 0 and array[j] > key:
        array[j + 1] = array[j]
        j -= 1
    array[j + 1] = key

# Print the sorted array in ascending order
print("Sorted Array (Ascending):", array)

# Print the sorted array in descending order
print("Sorted Array (Descending):", array[::-1])
