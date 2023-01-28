#!/usr/bin/env python3
import matplotlib.pyplot as plt

# Function for calculating the control updates
def control_update(beliefs):
    belief_bar = [0, 0, 0, 0]

    for current_position in range(4):
        position_belief = []

        for previous_position in range(4):
            current_probability = transition_probability(current_position, previous_position) * beliefs[previous_position]
            position_belief.append(current_probability)

        belief_bar[current_position] = round(sum(position_belief), 4)
    
    return belief_bar

# Measurement step
def measurement_update(beliefs, step):
    measurement_beliefs = []
    position_values = ['W', 'D', 'W', 'D']

    print("Enter measurement, D for door or W for wall")
    measurement = input()

    for position in range(4):
        truth = position_values[position]
        percentage = lookup(measurement, truth)
        measurement_beliefs.append(percentage * beliefs[position])
    
    # calculate the normalization factor and get the normlized values for 
    # belief bar
    nomrmalization_factor = 1 / sum(measurement_beliefs)
    normalized = [round(value * nomrmalization_factor, 4) for value in measurement_beliefs]
    
    return normalized

# look up function to return the percentage chance of the robots position 
# based on the measurement reading and what the position's truth
def lookup(measurement, position_truth):
    measurement_no_case = measurement.casefold()
    truth_no_case = position_truth.casefold()
    
    if measurement_no_case == truth_no_case:
        if measurement_no_case == 'D'.casefold():
            return .7
        elif measurement_no_case == 'W'.casefold():
            return .75
        else:
            return 0
    else:
        if measurement_no_case == 'D'.casefold():
            return 0.25
        elif measurement_no_case == 'W'.casefold():
            return .3
        else:
            return 0


# returns the normlization factor
def normalize(measurement_beliefs):
    return 1 / sum(measurement_beliefs)

# return the probability for trasition between the current and previous position
def transition_probability(current_position, previous_position):

    # positions are the same robot slips and probability is 20%
    # robot moved one position probability is 70%
    # robot moved two positions probabilty is 10%
    # robot moves backward probability is 0%
    if current_position == previous_position:
        return 0.2
    elif current_position - 1 == previous_position: 
        return .7
    elif current_position - 2 == previous_position: 
        return .1
    else: 
        return 0

def main():
    beliefs = [0.25, 0.25, 0.25, 0.25]
    transition_beliefs = []

    for transition_step in range(4):

        control_update_beliefs = control_update(beliefs)

        belief_bar = measurement_update(control_update_beliefs, transition_step)

        transition_beliefs.append(belief_bar)

        beliefs = belief_bar
    
    for index in range(len(transition_beliefs)):
        print(f'Belief bar values at T{index}: {transition_beliefs[index]}')
    
    x_axis_labels = ['P0', 'P1', 'P2', 'P3']

    plt.subplot(2, 2, 1)
    plt.bar(x_axis_labels, transition_beliefs[0])
    plt.title("T0")

    plt.subplot(2, 2, 2)
    plt.bar(x_axis_labels, transition_beliefs[1])
    plt.title("T1")

    plt.subplot(2, 2, 3)
    plt.bar(x_axis_labels, transition_beliefs[2])
    plt.title("T2")

    plt.subplot(2, 2, 4)
    plt.bar(x_axis_labels, transition_beliefs[3])
    plt.title("T3")

    plt.show()

if __name__ == '__main__':
    main()