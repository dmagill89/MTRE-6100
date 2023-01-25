#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np

def control_update(beliefs, current_step):
    for index in range(len(beliefs)):
        current_belief = beliefs[index]
        probability = transition_probability()

def measurement_update():
    print("calculate measurements")

# returns the normlization factor
def normalize(partial_belifs):
    return 1 / sum(partial_belifs)

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
    positions = [0, 1, 2, 3]
    position_lookup = ['wall', 'door', 'wall', 'door']

    for index in range(4):
        
        for current_position in positions:
            belief_bar = []

            for previous_position in positions:
            
                current_probability = transition_probability(current_position, previous_position) * beliefs[previous_position]
                belief_bar.append(current_probability)
                
            print(belief_bar)

if __name__ == '__main__':
    main()