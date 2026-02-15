import matplotlib.pyplot as plt


plt.figure(num=1,figsize=(10,5)) # create a new figure with specified size
plt.subplot(2,2,1) # create a subplot in a 2x2 grid, and this is the first subplot
plt.plot([0,1],[0,1]) # plot a line from (0,0) to (1,1)
plt.subplot(2,2,2) # create a subplot in a 2x2 grid, and this is the second subplot
plt.plot([0,1],[1,0]) # plot a line from (0,1) to (1,0)
plt.subplot(2,2,3) # create a subplot in a 2x2 grid, and this is the third subplot
plt.plot([0,1],[0.5,0.5]) # plot a horizontal line at y=0.5
plt.subplot(2,2,4) # create a subplot in a 2x2 grid, and this is the fourth subplot
plt.plot([0.5,0.5],[0,1]) # plot a vertical line at x=0.5

plt.figure(num=2,figsize=(10,5)) # create another figure with specified size
plt.subplot(211) # create a subplot in a 2x1 grid, and this is the first subplot
plt.plot([0,1],[0,1]) # plot a line from (0,0) to (1,1)
plt.subplot(234) # create a subplot in a 2x3 grid, and this is the fourth subplot (second row, first column)
plt.plot([0,1],[1,0]) # plot a line from (0,1) to (1,0)
plt.subplot(235) # create a subplot in a 2x3 grid, and this is the fifth subplot (second row, second column)
plt.plot([0,1],[0.5,0.5]) # plot a horizontal line at y=0.5
plt.subplot(236) # create a subplot in a 2x3 grid, and this is the sixth subplot (second row, third column)
plt.plot([0.5,0.5],[0,1]) # plot a vertical line at x=0.5
# in this way, the first subplot (211) occupies the entire first row, while the second row is divided into three subplots (234, 235, 236). 

plt.show()