import matplotlib.pyplot as plt
from radioactive import RadioactiveDecay

# Create a RadioactiveDecay object
rd = RadioactiveDecay('Mo-99')

# Create a figure with a line chart
fig, ax = plt.subplots()
ax.plot(rd.get_time(), rd.get_activity())

# Display the plot inline
plt.ion()
plt.show()