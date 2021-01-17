"""
Code to calculate the circle that passes through three given points.

Fill in each function with your code (including fixing the return
statement).
"""

import math
import comp140_module1 as circles

def distance(point0x, point0y, point1x, point1y):
    """
    Computes the distance between two points.

    inputs:
        -point0x: a float representing the x-coordinate of the first point
        -point0y: a float representing the y-coordinate of the first point
        -point1x: a float representing the x-coordinate of the second point
        -point1y: a float representing the y-coordinate of the second point

    returns: a float that is the distance between the two points
    """
    distance = math.sqrt((point0x-point1x)**2 + (point0y-point1y)**2)
    return distance

def midpoint(point0x, point0y, point1x, point1y):
    """
    Computes the midpoint between two points.

    inputs:
        -point0x: a float representing the x-coordinate of the first point
        -point0y: a float representing the y-coordinate of the first point
        -point1x: a float representing the x-coordinate of the second point
        -point1y: a float representing the y-coordinate of the second point

    returns: two floats that are the x- and y-coordinates of the midpoint
    """
    xcoord = point0x + ((point1x-point0x)/2.0)
    ycoord = point0y + ((point1y-point0y)/2.0)
    return xcoord, ycoord

def slope(point0x, point0y, point1x, point1y):
    """
    Computes the slope of the line that connects two given points.

    The x-values of the two points, point0x and poin1x, must be different.

    inputs:
        -point0x: a float representing the x-coordinate of the first point.
        -point0y: a float representing the y-coordinate of the first point
        -point1x: a float representing the x-coordinate of the second point.
        -point1y: a float representing the y-coordinate of the second point

    returns: a float that is the slope between the points
    """
    slope = (point1y-point0y) / (point1x-point0x)
    return slope

def perp(lineslope):
    """
    Computes the slope of a line perpendicular to a given slope.

    input:
        -lineslope: a float representing the slope of a line.
                    Must be non-zero

    returns: a float that is the perpendicular slope
    """
    perpslope = (-1.0) / (lineslope)
    return perpslope

def intersect(slope0, point0x, point0y, slope1, point1x, point1y):
    """
    Computes the intersection point of two lines.

    The two slopes, slope0 and slope1, must be different.

    inputs:
        -slope0: a float representing the slope of the first line.
        -point0x: a float representing the x-coordinate of the first point
        -point0y: a float representing the y-coordinate of the first point
        -slope1: a float representing the slope of the second line.
        -point1x: a float representing the x-coordinate of the second point
        -point1y: a float representing the y-coordinate of the second point

    returns: two floats that are the x- and y-coordinates of the intersection
    point
    """
    intersect_x = ((slope0*point0x/1.0)-(slope1*point1x)+(point1y-point0y)) / (slope0-slope1)
    intersect_y = (slope0/1.0) * (intersect_x - point0x) + point0y
    return intersect_x, intersect_y

def make_circle(point0x, point0y, point1x, point1y, point2x, point2y):
    """
    Computes the center and radius of a circle that passes through
    thre given points.

    The points must not be co-linear and no two points can have the
    same x or y values.

    inputs:
        -point0x: a float representing the x-coordinate of the first point
        -point0y: a float representing the y-coordinate of the first point
        -point1x: a float representing the x-coordinate of the second point
        -point1y: a float representing the y-coordinate of the second point
        -point2x: a float representing the x-coordinate of the third point
        -point2y: a float representing the y-coordinate of the third point

    returns: three floats that are the x- and y-coordinates of the center
    and the radius
    """
    slope_first = slope(point0x, point0y, point1x, point1y)
    midpoint_first_x, midpoint_first_y = midpoint(point0x, point0y, point1x, point1y)
    perp_first = perp(slope_first)
    
    slope_second = slope(point0x, point0y, point2x, point2y)
    midpoint_second_x, midpoint_second_y = midpoint(point0x, point0y, point2x, point2y)
    perp_second = perp(slope_second)
    
    center_x, center_y = intersect(perp_first, midpoint_first_x, midpoint_first_y, perp_second, midpoint_second_x, midpoint_second_y)
    radius = distance(center_x, center_y, point0x, point0y)
    
    
    return center_x, center_y, radius

center_x, center_y, radius = make_circle(199.0, 34.0, 71.0, 65.0, 181, 105) 

# Run GUI - uncomment the line below after you have
#           implemented make_circle
#circles.start(make_circle)
