import radioactivedecay as rd
import termux

# Create the plot
nuc = rd.nucleid('Mo-99')
plot = nuc.plot(kind='line', x='energy', y='intensity')

# Display the plot in a new ion window
termux.ion(plot)