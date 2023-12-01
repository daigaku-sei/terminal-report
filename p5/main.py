import math
import matplotlib.pyplot as plt
from rich import print

# Constants
m = 1.01*500
k = 1.07*6100
g = 9.8
U = 3
mu = 430

print(f"[green]Welcome to Program 5 of familiarisation report![/green]")
print(f"[yellow]Dynamics of a material point[/yellow]")
print(f"[bold]Free descent of a cable car[/bold]")
print(f"[green]Task[/green] is to collect data and make graphs")

print("[bold yellow]System:[/bold yellow]")
print(f"a_x = -mu * vel_x / m + mu*U*math.cos(math.radians(5))/m + g* math.sin(math.radians(10))\n\
a_y = -mu * vel_y / m - k  * y / m - mu*U*math.sin(math.radians(5))/m - g* math.cos(math.radians(10))")

print("[bold cyan]Where const(standard units):[/bold cyan]")
print(f"[italic]mu[/italic] is the coefficient of friction = {mu}")
print(f"[italic]m[/italic] is mass = {m}")
print(f"[italic]U[/italic] is an enviromental force = {U}")
print(f"[italic]g[/italic] is the acceleration due to gravity = {g}")
print(f"[italic]k[/italic] is a constant factor characteristic of the spring = {k}")

a_lambda = 1

# Calculate the typical transition time
tx = abs(  (-a_lambda - 0) / (mu/m)  )
tt = abs(  (-a_lambda - k/m) / (mu/m)  )
print(f"[bold]The typical transition time is:[/bold] {max(tx, tt)}")

# target
koeff = 0.14
target_y = (- mu*U*math.sin(math.radians(5))/m - g* math.cos(math.radians(10)) ) *m / k
target_vx = mu*U*math.cos(math.radians(5))/m + g* math.sin(math.radians(10)) * m / mu
print(f"[bold]Targets for y, vx:[/bold] {target_y, target_vx}")

# Initial conditions
x = 0
y = koeff * (- mu*U*math.sin(math.radians(5))/m - g* math.cos(math.radians(10)) ) *m /k
vel_x = -1.8 * math.sin(math.radians(10))
vel_y = 1.8 * math.cos(math.radians(10))
print(f"[yellow]Initial conditions:[/yellow]")
print(f"x0 = 0, y0 = {y}, vx0 = {vel_x}, vy0 = {vel_y}")

# Time step and duration
dt = 1 / tt / 24  # Choose an appropriate time step
duration = tt  # Duration of simulation in seconds

# Lists to store position values
time = []
position_x = []
position_y = []
position_vx = []
position_vy = []

# Simulation loop
for t in range(int(duration / dt)):
    # Calculate acceleration
    a_x = -mu * vel_x / m + mu*U*math.cos(math.radians(5))/m + g* math.sin(math.radians(10))
    a_y = -mu * vel_y / m - k  * y / m - mu*U*math.sin(math.radians(5))/m - g* math.cos(math.radians(10))

    # Update velocity
    vel_x += a_x * dt
    vel_y += a_y * dt

    # Update position
    x += vel_x * dt
    y += vel_y * dt

    # Store position values
    time.append(t * dt)
    position_x.append(x)
    position_y.append(y)
    position_vx.append(vel_x)
    position_vy.append(vel_y)

# Plotting the equilibrium states
plt.figure(figsize=(12, 4))

# Equilibrium state for y and vy
plt.subplot(131)
plt.plot(time, [target_y] * len(time), 'b--', label=f'y = {target_y:.2}')
plt.plot(time, position_y, label='Calculated y')

plt.plot(time, [0] * len(time), 'r--', label='vy = 0')
plt.plot(time, position_vy, label='Calculated vy')

plt.xlabel('Time (s)')
plt.ylabel('y, vy')
plt.title('Equilibrium State for y')
plt.legend()
plt.grid(True)

# Equilibrium state for x
plt.subplot(132)
plt.plot(time, [target_vx * t for t in time], 'b--', label=f'x = {target_vx:.3} * t')
plt.plot(time, position_x, label='Calculated x')

plt.plot(time, [target_vx] * len(time), 'r--', label=f'vx = {target_vx:.3}')
plt.plot(time, position_vx, label='Calculated vx')

plt.xlabel('Time (s)')
plt.ylabel('x, vx')
plt.title('Equilibrium State for x')
plt.legend()
plt.grid(True)

# Equilibrium state for y(x)
plt.subplot(133)
plt.plot([target_vx * t for t in time], [target_y] * len(time), 'r--', label='y(x)')
plt.plot(position_x, position_y, label='Calculated y(x)')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Equilibrium State for y(x)')
plt.legend()
plt.grid(True)

plt.tight_layout()

output = 'p5.png'
plt.savefig(output)
print(f"[bold green]Success![/bold green]")
print(f"[bold yellow]Plot saved: [bold yellow][bold green]{output}[/bold green]")