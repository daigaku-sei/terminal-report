import random

def count_odd_even(arr):
    odd_count = 0
    even_count = 0
    
    for num in arr:
        if num % 2 == 0:
            even_count += 1
        else:
            odd_count += 1
    
    return odd_count, even_count

def search_value(array):
    while True:
        value = input("Enter a value to search in the array (type 666 to exit): ")
        if value == '666':
            break
        try:
            value = int(value)
            indexes = [i for i, num in enumerate(array) if num == value]
            count = len(indexes)
            print("Indexes:", indexes)
            print("Count:", count)
        except ValueError:
            print("Invalid input. Please enter a valid integer or '666' to exit.")

print("______\n")
print("\n p1: [9] => T3,I3,M1: array operations on [N]x1 of random int\n")
print("______")

while True:
    number = input("Enter N size number of elements for [N]x1 array: ")
    try:
        size = int(number)
        if size <= 0:  # if not a positive int print message and ask for input again
            print("Sorry, input must be a positive integer, try again")
            continue
        break
    except ValueError:
        print("That's not an int!")

# Ask user for a number
while True:
    number = input(f"Guess a number in -100..100 to be randomed in [N={size}]x1: ")
    try:
        number = int(number)
        break
    except ValueError:
        print("Invalid input. Please enter a valid integer.")

# Create an array of random integers from -100 to 100
array = [random.randint(-100, 100) for _ in range(size)]

# Calculate the count of odd and even elements in the array
odd_count, even_count = count_odd_even(array)

# Initialize variables
SUM = sum(array)
PRODUCT = 1
min_value = min(array)
min_indexes = [i for i, num in enumerate(array) if num == min_value]
max_value = max(array)
max_indexes = [i for i, num in enumerate(array) if num == max_value]
guess_indexes = [i for i, num in enumerate(array) if num == number]
GUESS_COUNT = len(guess_indexes)

# Calculate product
for num in array:
    PRODUCT *= num

# Luck?
print("\nNumber", number, "Presence:")
print("Indexes:", guess_indexes)
print("Count:", GUESS_COUNT)
if GUESS_COUNT:
    print("Lucky guess!")
else:
    print("Better luck next time!")

# Print the array
print("\nOriginal array:", array)

print("\nI. min|MAX\nMinimum Value:", min_value)
print("Minimum Indexes:", min_indexes)
print("Maximum Value:", max_value)
print("Maximum Indexes:", max_indexes)

# Print the properties
print("\nII. +|*\nSum:", format(SUM, ','))
print("Product:", format(PRODUCT, ','))

# Calculate mean and geometric mean
mean = SUM / len(array)
geometric_mean = PRODUCT ** (1 / len(array))

# Print (pretty) mean and geometric mean
print("\nIII. mean|geomean\nMean: {:.3f}".format(mean))
print("Geometric Mean: {:.3f}".format(geometric_mean))

# Print odd and even count
print("\nIV. odd|even\nOdd count:", odd_count)
print("Even count:", even_count)

# Sort the array using the sorted() function
# sorted_array = in_serted(array)

# Sort by insertion fn
def insertion_sort(arr):
    arr_size = len(arr)
	len(set(arr)) <= 1:
        print("Nothing to sort here!")
		return arr # If the array has 0 or 1 element, it is already sorted, so return
	for i in range(1, arr_size): # Iterate over the array starting from the second element
		key = arr[i] # Store the current element as the key to be inserted in the right position
		j = i-1
		while j >= 0 and key < arr[j]: # Move elements greater than key one position ahead
			arr[j+1] = arr[j] # Shift elements to the right
			j -= 1
		arr[j+1] = key # Insert the key in the correct position
    return arr

# Use custom (by insertion) sort fn
sorted_array = insertion_sort(array)

# Print the sorted array in ascending order
print("\nV. sort by insertion\nSorted Array (Ascending):", sorted_array)

# Print the sorted array in descending order
print("Sorted Array (Descending):", sorted_array[::-1])

# Search for a value in the array until the user types 666
search_value(array)
