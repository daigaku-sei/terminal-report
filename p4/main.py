import numpy as np
from scipy.special import ellipk
import matplotlib.pyplot as plt

def calculate_period(phi0, l, g):
    T = 4 * np.sqrt(l / g) * ellipk(np.sin(phi0 / 2))
    return T

def save_data(l_values, phi0_values, g):
    data = []
    for i, l in enumerate(l_values):
        l_data = []
        for phi0 in phi0_values:
            T = calculate_period(phi0, l, g)
            l_data.append((phi0, T))
        data.append((l, l_data))
    
    return data

def plot_data(data):
    fig, ax = plt.subplots()
    for l, l_data in data:
        phi0_values, T_values = zip(*l_data)
        ax.plot(phi0_values, T_values, label=f"l = {l}")
    ax.set_xlabel("phi0")
    ax.set_ylabel("T")
    ax.legend()
    return fig

def calculate_and_save_data(a, b, l_values, g):
    phi0_values = np.linspace(a, b, 1000)
    data = save_data(l_values, phi0_values, g)
    
    if data:
        fig = plot_data(data)
        fig.savefig("all_in_one_plot.png")
        
        for i, (l, l_data) in enumerate(data):
            fig, ax = plt.subplots()
            phi0_values, T_values = zip(*l_data)
            ax.plot(phi0_values, T_values)
            ax.set_xlabel("phi0")
            ax.set_ylabel("T")
            ax.set_title(f"l = {l}")
            fig.savefig(f"plot_{i+1}.png")
            
            with open(f"{i+1}.txt", "w") as file:
                file.write(f"#l = {l}\n")
                for phi0, T in l_data:
                    file.write(f"{phi0}\t{T}\n")

# Get the bounds
a_min = -np.pi / 2
a_max = np.pi / 2
b_min = 0.0
b_max = np.pi / 2

a = input(f"Enter the lower bound for phi0 (hit Enter for {a_min}): ")
if a == "":
    a = a_min
else:
    while True:
        try:
            a = float(a)
            if a < a_min or a > a_max:
                raise ValueError
            break
        except ValueError:
            print("Invalid value entered.")
            a = input(f"Enter the lower bound for phi0 ({a_min}): ")

b = input(f"Enter the upper bound for phi0 (hit Enter for {b_max}): ")
if b == "":
    b = b_max
else:
    while True:
        try:
            b = float(b)
            if b < b_min or b > b_max or a > b:
                raise ValueError
            break
        except ValueError:
            print("Invalid value entered.")
            b = input(f"Enter the upper bound for phi0 ({b_max}): ")

# Get the number of l values from the user
num_l = input("Enter the number of l values: ")
while True:
    try:
        num_l = int(num_l)
        if num_l <= 0:
            raise ValueError
        break
    except ValueError:
        print("Invalid value entered.")
        num_l = input("Enter the number of l values: ")

# Get the l values from the user
l_values = []
while len(l_values) < num_l:
    l = input(f"Enter l value {len(l_values)+1}: ")
    while True:
        try:
            l = float(l)
            if l <= 0:
                raise ValueError
            break
        except ValueError:
            print("Invalid value entered.")
            l = input(f"Enter l value {len(l_values)+1}: ")
    if l not in l_values:
        l_values.append(l)
    else: print(f"ignoring repeat {l}")
    print(f"l values are: {l_values}")

# Calculate and save the data
calculate_and_save_data(a, b, l_values, 9.8)
print("Plots are in the dir of a py file")
