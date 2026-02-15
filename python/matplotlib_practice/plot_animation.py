import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

fig, ax = plt.subplots() # create a figure and a set of subplots
x = np.arange(0, 2*np.pi, 0.01) # generate values from 0 to 2*pi with a step of 0.01 for x-axis
line, = ax.plot(x, np.sin(x)) # plot the initial sine wave and get the line object
def update(frame):
    line.set_ydata(np.sin(x + frame / 10)) # update the y-data of the line to create an animation effect
    return line, # return the line object as a tuple which is required by FuncAnimation
ani = animation.FuncAnimation(fig, update, frames=100, interval=50, blit=True) # create an animation by repeatedly calling the update function
# frames=100 means the update function will be called 100 times, 
# interval=50 means there will be a 50 millisecond delay between each call to the update function,
# and blit=True means only the parts of the plot that have changed will be redrawn, 
# which can improve performance.
plt.show() # display the plot with the animation