"""
Stock market prediction using Markov chains.

For each function, replace the return statement with your code.  Add
whatever helper functions you deem necessary.
"""

import comp140_module3 as stocks
from collections import defaultdict
import random


def empty_dict():
    """
    Helper function for markov_chain to allow defaultdict to set the default
        to a dictionary with defaultdict applied
    
    inputs:
        none
        
    returns: a default dictionary with default value of 0.0
    """
    return defaultdict(float)


### Model

def markov_chain(data, order):
    """
    Create a Markov chain with the given order from the given data.

    inputs:
        - data: a list of ints or floats representing previously collected data
        - order: an integer repesenting the desired order of the markov chain

    returns: a dictionary that represents the Markov chain
    """
    final_chain = defaultdict(empty_dict)
    offset = 0
    
    while offset < (len(data)-order):
        key = []
        for number in range(order):
            key.append(data[number+offset])
        #print(key)
        tuple_key = tuple(key)
        final_chain[tuple_key][data[order+offset]] += 1.0
        offset += 1
    #print(final_chain)
    
    for base_key, base_value in final_chain.items():
        total = 0
        
        final_chain[base_key] = dict(base_value)
        #print(base_value)
        
        for inner_value in final_chain[base_key].values():
            #print(inner_value)
            #for inner_value in inner_map.values():
            total += inner_value
        for inner_key in final_chain[base_key].keys():
                #print(inner_value)
                #print(final_chain[inner_key])
            final_chain[base_key][inner_key] /= total

    #print (dict(final_chain))
    return dict(final_chain)

#markov_chain([1,1,1],1)

### Predict

def weighted_choice(prob_dict):
    """
    Given a dictionary of values and their probabilities, returns
    a value chosen with respect to the probability
    Assume the values add to one and only one
    
    Input:
        prob_dict - a dictionary with anything(that is possible) as a key and
        probabilities as the values
        
    Output:
        choice - the chosen key
    """
    keys = []
    probabilities = []
    for key, value in prob_dict.items():
        keys.append(key)
        probabilities.append(value)
        #print(key)
        #print(value)
        
    chance = random.random()
    previous = 0.0
    for num in range(len(probabilities)):
        if previous <= chance < (probabilities[num]+previous):
            #print(keys[num])
            return keys[num]
        
        previous += probabilities[num]
    return keys[0]


        
def predict(model, last, num):
    """
    Predict the next num values given the model and the last values.

    inputs:
        - model: a dictionary representing a Markov chain
        - last: a list (with length of the order of the Markov chain)
                representing the previous states
        - num: an integer representing the number of desired future states

    returns: a list of integers that are the next num states
    """
    default = {0: 0.25, 1: 0.25, 2: 0.25, 3:0.25}
    last_copy = last.copy()
    order = len(last)
    offset = 0
    prediction = []
    while offset < num:
        #last_state = last_copy[len(last_copy)-offset:]
        last_copy.reverse()
        last_state = last_copy[:order]
        last_copy.reverse()
        last_state.reverse()
            
        last_tuple = tuple(last_state)
        #print(last_copy)
        #print(last_tuple)
        if last_tuple in model:
            #print(last_tuple)
            #print(model[last_tuple])
            latest = weighted_choice(model[last_tuple])
        else:
            latest = weighted_choice(default)
        last_copy.append(latest)
        prediction.append(latest)
        offset += 1
            
    return prediction

#print(predict({(0,): {1: 1}, (1,): {0: 1}}, [0], 3))

### Error

def mse(result, expected):
    """
    Calculate the mean squared error between two data sets.

    The length of the inputs, result and expected, must be the same.

    inputs:
        - result: a list of integers or floats representing the actual output
        - expected: a list of integers or floats representing the predicted output

    returns: a float that is the mean squared error between the two data sets
    """
    combo = zip(result, expected)
    error = 0
    for actual, predicted in combo:
        error += ((actual - predicted) ** 2) / len(result)
    return error


### Experiment

def run_experiment(train, order, test, future, actual, trials):
    """
    Run an experiment to predict the future of the test
    data given the training data.

    inputs:
        - train: a list of integers representing past stock price data
        - order: an integer representing the order of the markov chain
                 that will be used
        - test: a list of integers of length "order" representing past
                stock price data (different time period than "train")
        - future: an integer representing the number of future days to
                  predict
        - actual: a list representing the actual results for the next
                  "future" days
        - trials: an integer representing the number of trials to run

    returns: a float that is the mean squared error over the number of trials
    """
    total = 0
    count = 0
    while count < trials:
        prediction = predict(markov_chain(train, order), test, future)
        total += mse(actual, prediction)
        count += 1
    total /= trials
        
    return total


### Application

def run():
    """
    Run application.

    You do not need to modify any code in this function.  You should
    feel free to look it over and understand it, though.
    """
    # Get the supported stock symbols
    symbols = stocks.get_supported_symbols()

    # Get stock data and process it

    # Training data
    changes = {}
    bins = {}
    for symbol in symbols:
        prices = stocks.get_historical_prices(symbol)
        changes[symbol] = stocks.compute_daily_change(prices)
        bins[symbol] = stocks.bin_daily_changes(changes[symbol])

    # Test data
    testchanges = {}
    testbins = {}
    for symbol in symbols:
        testprices = stocks.get_test_prices(symbol)
        testchanges[symbol] = stocks.compute_daily_change(testprices)
        testbins[symbol] = stocks.bin_daily_changes(testchanges[symbol])

    # Display data
    #   Comment these 2 lines out if you don't want to see the plots
    stocks.plot_daily_change(changes)
    stocks.plot_bin_histogram(bins)

    # Run experiments
    orders = [1, 3, 5, 7, 9]
    ntrials = 500
    days = 5

    for symbol in symbols:
        print(symbol)
        print("====")
        print("Actual:", testbins[symbol][-days:])
        for order in orders:
            error = run_experiment(bins[symbol], order,
                                   testbins[symbol][-order-days:-days], days,
                                   testbins[symbol][-days:], ntrials)
            print("Order", order, ":", error)
        print()

# You might want to comment out the call to run while you are
# developing your code.  Uncomment it when you are ready to run your
# code on the provided data.

# run()
