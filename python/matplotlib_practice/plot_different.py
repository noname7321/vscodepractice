import matplotlib.pyplot as plt
import numpy as np

n=1024
X=np.random.normal(0,1,n) # mean=0, std=1, n samples
Y=np.random.normal(0,1,n)
T=np.arctan2(Y,X) # angle between the x-axis and the point (X,Y),for color mapping
plt.scatter(X,Y,s=75,c=T,alpha=0.5) 
# s is the size of the points, c is the color of the points,
# alpha is the transparency of the points

plt.xlim(-1.5,1.5) # set x-axis limits,from -1.5 to 1.5
plt.ylim(-1.5,1.5) # set y-axis limits
plt.xticks(()) # remove x-axis ticks
plt.yticks(()) # remove y-axis ticks

plt.show()