import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

fig=plt.figure(num=1,figsize=(10,5))
#ax=Axes3D(fig) # create a 3D axes object in the figure
ax = fig.add_subplot(111, projection='3d')  # 推荐方式
# 111 表示在 1 行 1 列的网格中创建一个子图，并且这个子图占满整个网格（即第 1 个位置）。projection='3d' 参数指定这个子图是一个 3D 图.

X=np.arange(-4,4,0.25) # generate values from -4 to 4 with a step of 0.25 for x-axis
Y=np.arange(-4,4,0.25) # generate values from -4 to 4 with a step of 0.25 for y-axis
X,Y=np.meshgrid(X,Y) # create a 2D grid of x and y values
R=np.sqrt(X**2+Y**2) # calculate the distance from the origin for each point in the grid
Z=np.sin(R) # calculate the z value as the sine of the distance from the origin

ax.plot_surface(X,Y,Z,rstride=1,cstride=1,cmap=plt.get_cmap('rainbow'))
# plot_surface() creates a 3D surface plot of the function Z over the grid defined by X and Y.
# rstride and cstride specify the row and column stride for sampling the data to plot,
# retride=1 means use every row, cstride=1 means use every column,
#  so the surface will be plotted with all the data points.
# cmap=plt.cm.hot specifies the colormap to use for coloring the surface.

plt.show()