# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 20:58:24 2023
Used black to autoformat
Used Spyder code analysis

@author: 325A R
"""


import random


print("______\n")
print("\n p1: [9] => T3,I3,M1: array operations on 1x[N] of random int\n")
print("______")

# Ask user for a number
number = int(input("Enter a number: "))

# Create an array of random integers from -100 to 100
array = [random.randint(-100, 100) for _ in range(10)]

# Initialize variables
SUM = 0
PRODUCT = 1
min_value = float("inf")
min_indexes = []
max_value = float("-inf")
max_indexes = []
guess_indexes = []
GUESS_COUNT = 0

# Collect data while initializing
for i, num in enumerate(array):
    SUM += num
    PRODUCT *= num

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
        GUESS_COUNT += 1

# Print the array
print("Array:", array)

# Print the properties
print("Sum:", SUM)
print("Product:", PRODUCT)
print("Minimum Value:", min_value)
print("Minimum Indexes:", min_indexes)
print("Maximum Value:", max_value)
print("Maximum Indexes:", max_indexes)
print("Number", number, "Presence:")
print("Indexes:", guess_indexes)
print("Count:", GUESS_COUNT)

# Calculate mean and geometric mean
mean = SUM / len(array)
geometric_mean = PRODUCT ** (1 / len(array))

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
