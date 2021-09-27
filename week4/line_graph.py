##  Assignment:   CSCI205 Week 4 Lab
##  line_graph.py - a python program to create line graphs for algorithm analysis using matplotlib

##  Version       1.0 Beta
##  Author        Dan Caruso
##  Created       9/23/2021

import matplotlib.pyplot as plt

## Create lists for x and y coordinates
x = []
y = []

## Have the user input a file name to plot
print('Please type in full file name: ')
file_name = input()

## try/except block to validate correct file name entry
try:
    ## Open the file, read the lines in, close the file
    f = open(file_name)
    lines = f.readlines()
    f.close()

    xMax = 0
    yMax = 0

    ## For each line read in, split the values and enter the first as an x coordinate, second as a y coordinate
    for line in lines:
        coords = line.split()
        xCoord = int(coords[0])
        yCoord = int(coords[1])
        x.append(xCoord)
        y.append(yCoord)

        if(xCoord > xMax):
            xMax = xCoord
        if(yCoord > yMax):
            yMax = yCoord

    ## ylim for exercise_3 and searches_binary: (0, 100)
    ## for all others: (xMax, yMax)

    ## Plot properties
    plt.plot(x, y, 'b')
    plt.title(file_name)
    plt.xlim(0, xMax)
    plt.xlabel("Problem Size")
    plt.ylim(0, 100)
    plt.ylabel("Number of Steps Executed")
    plt.grid(True)
    ## plt.legend()
    plt.show()

## Kick out an error message if an invalid file name has been entered
except IOError:
    print('{} count not be opened - check the file name and try again'.format(file_name))
