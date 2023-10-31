import matplotlib.pyplot as plt
import radioactivedecay as rd

# Create a nucleid object
nuc = rd.nucleid('Mo-99')

# Plot the decay chain
nuc.plot()

# Display the plot inline
plt.show()