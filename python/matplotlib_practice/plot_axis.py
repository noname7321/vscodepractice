import matplotlib.pyplot as plt
import numpy as np


x=np.linspace(0,10,100) # generate 100 evenly spaced values from 0 to 10
y1=0.05*x**2 # calculate y1 as a quadratic function of x
y2=-1*y1 # calculate y2 as the negative of y1
fig,ax1=plt.subplots() # create a figure and a set of subplots, and unpack the axes object
# fig is the figure object that contains all the elements of the plot, 
# and ax1 is the axes object that represents the area where the data will be plotted.
# subplots() is a convenient function that creates a figure and a grid of subplots with a single call.
ax1.plot(x,y1,'r-') # plot y1 against x in red color, and use solid lines
ax1.set_xlabel('x') # set the x-axis label of the first axes
ax1.set_ylabel('y1',color='r') # set the y-axis label of the first axes, and specify the color as red
ax2=ax1.twinx() # create a second axes object that shares the same x-axis as ax1
ax2.plot(x,y2,'b--') # plot y2 against x in blue color, and use dashed lines
ax2.set_ylabel('y2',color='b') # set the y-axis label of the second axes, and specify the color as blue


plt.figure(num=1,figsize=(10,5)) # create a new figure with specified size 
plt.show()