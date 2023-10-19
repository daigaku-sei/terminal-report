from radioactivedecay import DecayChain

# Define the decay chain
decay_chain = DecayChain()
decay_chain.add_parent("Uranium-238", half_life=4.5e9)
decay_chain.add_daughter("Thorium-234", branching_ratio=1)
decay_chain.add_daughter("Radium-226", branching_ratio=0.00055)
decay_chain.add_daughter("Radon-222", branching_ratio=0.99945)
decay_chain.add_daughter("Polonium-218", branching_ratio=0.006)
decay_chain.add_daughter("Lead-214", branching_ratio=0.994)
decay_chain.add_daughter("Bismuth-214", branching_ratio=1)
decay_chain.add_daughter("Polonium-214", branching_ratio=0.999998)
decay_chain.add_daughter("Lead-210", branching_ratio=2e-6)
decay_chain.add_daughter("Bismuth-210", branching_ratio=1)
decay_chain.add_daughter("Polonium-210", branching_ratio=1)

# Set initial activity and time
initial_activity = 1e6  # Bq
time = 10  # years

# Calculate the activity of each nuclide in the decay chain at the given time
activity_dict = decay_chain.calculate_activity(initial_activity, time)

# Print the activity of each nuclide
for nuclide, activity in activity_dict.items():
    print(f"{nuclide}: {activity:.2f} Bq")
