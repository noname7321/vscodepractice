from matplotlib import pyplot as plt
import numpy as np
# 1. Create a simple line plot
dev_x=[25,26,27,28,29,30,31,32,33,34,35]
dev_y=[38496, 42000, 46752, 49320, 53200, 56000, 62316, 64928, 67317, 68748, 73752]
plt.figure(figsize=(10,5)) # set the figure size to 10 inches wide and 5 inches tall
plt.xlim(25,35) # set the x-axis limits
plt.ylim(35000,75000) # set the y-axis limitss
plt.xlabel('Ages') # set the x-axis label
plt.ylabel('Median Salary (USD)') # set the y-axis label
new_ticks=np.arange(25,36,1) # create new ticks for the x-axis from 25 to 35 with a step of 1
print(new_ticks) # print the new ticks to verify
plt.xticks(new_ticks) # set the new ticks on the x-axis
plt.yticks([35000,40000,45000,50000,55000,60000,65000,70000,75000],
           [r'$\text{extremely low}$', r'$\text{very low}$', r'$\text{low}$', r'$\text{lower medium}$', r'$\text{medium}$', r'$\text{above medium}$', r'$\text{high}$', r'$\text{very high}$', r'$\text{extremely high}$']) # set the y-axis ticks
# gca ='get current axis'
ax=plt.gca() # get the current axis,four spines are the borders of the plot
ax.spines['right'].set_color('none') # remove the right spine
ax.spines['top'].set_color('none') # remove the top spine
ax.xaxis.set_ticks_position('bottom') # set the x-axis ticks to the bottom
ax.yaxis.set_ticks_position('left') # set the y-axis ticks to the left
ax.spines['bottom'].set_position(('data',35000)) # x-axis and y-axis intersect at y=0
ax.spines['left'].set_position(('data',25)) # y-axis and x-axis intersect at x=25

plt.plot(dev_x,dev_y)
# plt.show() # display the plot 





x=np.linspace(0,5,11) # start from 0 to 5, with 11 evenly spaced points
y=x**2
plt.figure(num=2,figsize=(10,5)) # num=2 means this is the third figure,
#if we create another figure with num=2 , it will overwrite this one
plt.plot(x,y,label='x^2') # plot x^2
plt.plot(x,x**3,color='red',linewidth=2,linestyle='--',label='x^3') # plot x^3 on the same figure
plt.legend() # show the legend
plt.show() 