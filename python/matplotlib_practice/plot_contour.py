import matplotlib.pyplot as plt
import numpy as np

def f(x,y):
    return (1-x/2+x**5+y**3)*np.exp(-x**2-y**2) #function to be plotted, which is a combination of a polynomial and a Gaussian function

n=256
x=np.linspace(-3,3,n) # generate n evenly spaced values from -3 to 3 for x-axis
y=np.linspace(-3,3,n) # generate n evenly spaced values from -3 to 3 for y-axis

X,Y=np.meshgrid(x,y) # create a 2D grid of x and y values,
# meshgrid() takes two 1D arrays and produces two 2D arrays representing the grid of coordinates

# use plt.contourf() to filling contours
plt.contourf(X,Y,f(X,Y),12,alpha=0.75,cmap=plt.cm.hot)
# contourf() creates a filled contour plot of the function f(X,Y) over the grid defined by X and Y.
# 8 specifies the number of contour levels, 
# alpha=0.75 sets the transparency of the filled contours, 
# and cmap=plt.cm.hot specifies the colormap to use for coloring the contours.

# use plt.contour() to add contour lines on top of the filled contours, with specified line colors and widths
C=plt.contour(X,Y,f(X,Y),12,colors='black',linewidths=0.5)
# contour() creates contour lines for the same function f(X,Y) with the same levels (8),
# but with specified line colors and widths.

plt.clabel(C,inline=True,fontsize=10) # add labels to the contour lines, with specified font size


plt.xticks(()) # remove x-axis ticks
plt.yticks(()) # remove y-axis ticks
plt.show()