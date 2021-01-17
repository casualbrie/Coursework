"""
Code to implement the game of Spot it!

http://www.blueorangegames.com/spotit/

For each function, replace the return statement with your code.  Add
whatever helper functions you deem necessary.
"""

import comp140_module2 as spotit

def equivalent(point1, point2, mod):
    """
    Determines if the two given points are equivalent in the projective
    geometric space in the finite field with the given modulus.

    Each input point, point1 and point2, must be valid within the
    finite field with the given modulus.

    inputs:
        - point1: a tuple of 3 integers representing the first point
        - point2: a tuple of 3 integers representing the second point
        - mod: an integer representing the modulus

    returns: a boolean indicating whether or not the points are equivalent
    """
    
    line_x = ((point1[1] * point2[2]) - (point1[2] * point2[1])) % mod
    line_y = ((point1[2] * point2[0]) - (point1[0] * point2[2])) % mod
    line_z = ((point1[0] * point2[1]) - (point1[1] * point2[0])) % mod
    
    return (line_x == 0) and (line_y == 0) and (line_z == 0)

#print(equivalent((0,0,1),(0,1,0),2))

def incident(point, line, mod):
    """
    Determines if a point lies on a line in the projective
    geometric space in the finite field with the given modulus.

    The inputs point and line must be valid within the finite field
    with the given modulus.

    inputs:
        - point: a tuple of 3 integers representing a point
        - line: a tuple of 3 integers representing a line
        - mod: an integer representing the modulus

    returns: a boolean indicating whether or not the point lies on the line
    """
    
    #debugging prints
    #print(point[0] * line[0])
    #print(point[1] * line[1])
    #print(point[2] * line[2])
    #print(((point[0] * line[0]) + (point[1] * line[1]) + 
    #	(point[2] * line[2])) % mod)
    
    return ((point[0] * line[0]) + (point[1] * line[1]) + 
            (point[2] * line[2])) % mod == 0

#incident((6,0,2),(2,0,1),7)

def generate_all_points(mod):
    """
    Generate all unique points in the projective geometric space in
    the finite field with the given modulus.

    inputs:
        - mod: an integer representing the modulus

    Returns: a list of unique points, each is a tuple of 3 elements
    """
    #initializing necessary variables
    points_list = []
    is_in_list = False
    
    #finding every possible point in the given space
    for x_coord in range(mod):
        for y_coord in range(mod):
            for z_coord in range(mod):
                #checking to see if the point would be (0,0,0), which
                #	is invalid. If it is, then make the new point
                #	(0,0,1) as a way of avoiding too many nests and
                #	avoiding using break
                if (x_coord == 0 and y_coord == 0 and z_coord == 0):
                    z_coord = 1
                new_point = (x_coord, y_coord, z_coord)
                #print(new_point)
                #checking to see if the new point is in the list already
                is_in_list = False
                for point in points_list:
                    #print(new_point)
                    #print(point)
                    if equivalent(new_point, point, mod):
                        is_in_list = True
                        #print(point)
                        #print(new_point)
                        #print("hello")
                if not is_in_list:
                    points_list.append(new_point)
                    #print(new_point)
    
    return points_list

generate_all_points(2)

def create_cards(points, lines, mod):
    """
    Create a list of unique cards.

    Each point and line within the inputs, points and lines, must be
    valid within the finite field with the given modulus.

    inputs:
        - points: a list of unique points, each represented as a tuple of 3 integers
        - lines: a list of unique lines, each represented as a tuple of 3 integers
        - mod: an integer representing the modulus

    returns: a list of lists of integers, where each nested list represents a card.
    """
    return []

def run():
    """
    Create the deck and play the game.
    """
    # Prime modulus
    # Set to 2 or 3 during development
    # Set to 7 for the actual game
    modulus = 7

    # Generate all unique points for the given modulus
    # points = generate_all_points(modulus)

    # Lines are the same as points, so make a copy
    # lines = points[:]

    # Generate a deck of cards given the points and lines
    # deck = create_cards(points, lines, modulus)

    # Run GUI - uncomment the line below after you have implemented
    #           everything and you can play your game.  The GUI does
    #           not work if the modulus is larger than 7.

    # spotit.start(deck)

# Uncomment the following line to run your game (once you have
# implemented the run function.)

# run()
