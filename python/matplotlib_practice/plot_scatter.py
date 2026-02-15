import matplotlib.pyplot as plt
import numpy as np

plt.figure(num=1,figsize=(10,5)) # create a new figure with num=1 and size 10x5 inches
n=1024
X=np.random.normal(0,1,n) # mean=0, std=1, n samples
Y=np.random.normal(0,1,n)
T=np.arctan2(Y,X) # angle between the x-axis and the point (X,Y),for color mapping
plt.scatter(X,Y,s=75,c=T,alpha=0.5) 
plt.xlim(-1.5,1.5) # set x-axis limits,from -1.5 to 1.5
plt.ylim(-1.5,1.5) # set y-axis limits
plt.xticks(()) # remove x-axis ticks
plt.yticks(()) # remove y-axis ticks


plt.figure(num=2,figsize=(10,5)) # create a new figure with num=2 and size 10x5 inches
plt.scatter(np.arange(10),np.arange(10),s=100,c='red',alpha=0.5)
# np.arange(10) generates an array of integers from 0 to 9, 
# which are used as x and y coordinates for the second scatter plot.
# （点在 (0,0),(1,1),...,(9,9)）。
# s is the size of the points, c is the color of the points,
# alpha is the transparency of the points


plt.show()