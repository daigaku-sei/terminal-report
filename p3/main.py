import random

num_lines = 10

print("Type 666 at some point to exit")

# Write ordered lines to the file
with open("random_file.txt", "w") as file:
    for i in range(1, num_lines + 1):
        file.write(f"Line {i}\n")

# Read and display the contents of the file
def display_file_contents():
    with open("random_file.txt", "r") as file:
        print("Contents of the file:")
        for line in file:
            print(line.strip())

display_file_contents()

while True:
    try:
        n = int(input("Enter the line number to move: "))
        if n == 666:
            break;
        m = int(input("Enter the line number to move after: "))
        if m == 666:
            break;
    except ValueError:
        print("Invalid input. Please enter a valid integer.")
        continue

    # Check if the line numbers are valid
    if n < 1 or n > num_lines or m < 1 or m > num_lines:
        print(f"Invalid line numbers. Please enter numbers between 1 and {num_lines}.")
        continue

    lines = []
    with open("random_file.txt", "r") as file:
        lines = file.readlines()

    # Account for n < m
    if n < m:
        lines.insert(m-1, lines.pop(n-1))
    else:
        lines.insert(m, lines.pop(n-1))

    with open("random_file.txt", "w") as file:
        file.writelines(lines)

    if m == n or m == n - 1:
        print(f"Line {n} is already after line {m}.")
    else:
        print(f"Line {n} has been placed after line {m}.")

    # Read and display the updated contents of the file
    display_file_contents()

# Read and display the final contents of the file
display_file_contents()
