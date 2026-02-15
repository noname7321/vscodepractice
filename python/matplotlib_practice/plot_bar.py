import matplotlib.pyplot as plt
import numpy as np

n=12
X=np.arange(n) # generate 12 evenly spaced values from 0 to 11, 
#which will be used as x-coordinates for the bars
Y1=(1-X/float(n))*np.random.uniform(0.5,1.0,n) # generate 12 random values for the first bar
# np.random.uniform(0.5,1.0,n) generates n random values uniformly distributed between 0.5 and 1.0.(均匀分布)

Y2=(1-X/float(n))*np.random.uniform(0.5,1.0,n) # generate 12 random values for the second bar

plt.bar(X,Y1,facecolor='#9999ff',edgecolor='white') # plot the first bar with specified face and edge colors
# x-coordinates are given by X, heights of the bars are given by Y1,
# facecolor='#9999ff' sets the color of the bars to a light blue, edgecolor='white' sets the color of the bar edges to white
plt.bar(X,-Y2,facecolor='#ff9999',edgecolor='white') # plot the second bar with specified face and edge colors; 
#negative Y2 values to plot downward bars

for x,y in zip(X,Y1): # annotate the first bar with its height
    plt.text(x,y+0.05,'%.2f' % y, ha='center', va='bottom') 
    # x is the x-coordinate of the bar, y+0.05 is the y-coordinate for placing the text just above the top of the bar, 
    # '%.2f' % y formats the height value to two decimal places as a string,
    # ha='center' centers the text horizontally on the bar, va='bottom' places the text just above the top of the bar

for x,y in zip(X,-Y2): # annotate the second bar with its height
    plt.text(x,y-0.05,'-%.2f' % -y, ha='center', va='top') 
    # va='top' places the text just below the bottom of the bar

plt.xlim(-1,n) # set x-axis limits,from -1.5 to 1.5
plt.ylim(-1.25,1.25) # set y-axis limits
plt.xticks(()) # remove x-axis ticks
plt.yticks(()) # remove y-axis ticks

plt.show() # display the plot
