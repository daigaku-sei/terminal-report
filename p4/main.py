import numpy as np
from scipy.special import ellipk
import matplotlib.pyplot as plt
from rich import print


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

print(f"[green]Welcome to F01 of familiarisation report![/green]")
print(f"[green]Task[/green] is to collect data and make graphs")
print("[bold yellow]Period of a Simple Pendulum Formula:[/bold yellow]")
print(f"[bold]T[/bold] = 4 * sqrt([italic]l[/italic] / [italic]g[/italic]) * [italic]ellipk[/italic](sin([italic]phi0[/italic]/2))\n")
print("[bold cyan]Where:[/bold cyan]")
print(f"[bold]T[/bold] is the period of the pendulum")
print("[italic]l[/italic] is the length of the pendulum")
print("[italic]g[/italic] is the acceleration due to gravity")
print("[italic]ellipk[/italic] is the elliptic integral of the 1st kind")
print("[italic]phi0[/italic] is the maximum angle of displacement")
# Get the bounds
a_min = 0.0
a_max = 1.57
b_min = 0.01
b_max = np.pi/2
print(f"\n[cyan]Give different valid values for angle displacement range[/cyan]")
print(f"Angle displacement range: 0 to [bold cyan]half-pi[/bold cyan] radians")
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
            print(f"[red]Invalid value entered.[/red]")
            a = input(f"Enter the lower bound for phi0 >= {a_min}: ")

print(f"[bold]lower bound[/bold] is {a}")
b = input(f"Enter the upper bound for phi0 (default={b_max}): ")
if b == "":
    b = b_max
else:
    while True:
        try:
            b = float(b)
            if b < b_min or b > b_max or a >= b:
                raise ValueError
            break
        except ValueError:
            print(f"[red]Invalid value entered.[/red]")
            if a == b: print(f"[red]Error[/red]: a = b =", a)
            b = input(f"Enter the upper bound for phi0 <= {b_max}: ")

print(f"[italic]phi0[/italic]: from {a} to {b}")
# Get the number of l values from the user
print(f"\n[cyan]Give different valid values for pendulum length[/cyan]")
num_l = input("Enter the number of l values (default=2): ")
if num_l == "":
    num_l = 2
else:
    while True:
        try:
            num_l = int(num_l)
            if num_l <= 0:
                raise ValueError
            break
        except ValueError:
            print(f"[red]Invalid value entered.[/red]")
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
            print(f"[red]Invalid value entered.[/red]")
            l = input(f"Enter l value {len(l_values)+1}: ")
    if l not in l_values:
        l_values.append(l)
    else: print(f"ignoring repeat {l}")
    print(f"l values are: {l_values}")

# Calculate and save the data
calculate_and_save_data(a, b, l_values, 9.8)
print(f"[bold green]Success[/bold green]")
print(f"[bold yellow]Output in the dir of a py file[/bold yellow]")
print(f"Your data: 1.txt")
if num_l > 1:  print(f"\tupto {num_l}.txt")
print(f"Your plots: plot_[bold cyan]1[/bold cyan].png, all_in_one_plot.png")
if num_l > 1:  print(f"\tupto plot_[bold cyan]{num_l}[/bold cyan].png")

print( f"min(T) = {calculate_period(min(a,b), min(l_values), 9.8)}" )
print( f"max(T) = {calculate_period(max(a,b), max(l_values), 9.8)}" )