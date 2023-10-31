import radioactivedecay as rd

print('\nWelcome to radioactive decay package demo!')

print('\nMo99, of 2.0 Bq, after 20.0 hours,\n\tget Bq_activities/cumulative\n')
Mo99_t0 = rd.Inventory({'Mo-99': 2.0}, 'Bq')
Mo99_t1 = Mo99_t0.decay(20.0, 'h')
print(Mo99_t1.activities('Bq'))
print(Mo99_t0.cumulative_decays(20.0, 'h'))


print('\nH-3: 3.0 g, decay for 12.32 years,\n\tget masses/fract\n')
H3_t0 = rd.Inventory({'H-3': 3.0}, 'g')
H3_t1 = H3_t0.decay(12.32, 'y')
print(H3_t1.masses('g'))
print(H3_t1.mass_fractions())

print('\nC14: 3.2E24 num, for 3000 years,\n\tget moles/fractions\n')
C14_t0 = rd.Inventory({'C-14': 3.2E24}, 'num')
C14_t1 = C14_t0.decay(3000, 'y')
print(C14_t1.moles('mol'))
print(C14_t1.mole_fractions())

Mo99_t0.plot(20, 'd', yunits='Bq')

nuc = rd.Nuclide('Mo-99')
nuc.plot()
fig = nuc.plot()

# Save the plot as an image file
fig.savefig('Mo99.plot.png')