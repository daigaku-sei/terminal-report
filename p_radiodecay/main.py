from radioactive_decay import RadioactiveDecay

problem = RadioactiveDecay(
    substance='Uranium-238',
    initial_amount=1000,
    half_life=4.5e9,
    time_steps=100,
    time_unit='years'
)

problem.generate_code()
