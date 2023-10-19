import radioactivedecay as rd

Mo99_t0 = rd.Inventory({'Mo-99': 2.0}, 'Bq')
Mo99_t1 = Mo99_t0.decay(20.0, 'h')
>>> Mo99_t1.activities('Bq')

Mo99_t0.cumulative_decays(20.0, 'h')

H3_t0 = rd.Inventory({'H-3': 3.0}, 'g')
H3_t1 = H3_t0.decay(12.32, 'y')
H3_t1.masses('g')

H3_t1.mass_fractions()

C14_t0 = rd.Inventory({'C-14': 3.2E24}, 'num')
C14_t1 = C14_t0.decay(3000, 'y')
C14_t1.moles('mol')
C14_t1.mole_fractions()

Mo99_t0.plot(20, 'd', yunits='Bq')

nuc = rd.Nuclide('Mo-99')
nuc.plot()
