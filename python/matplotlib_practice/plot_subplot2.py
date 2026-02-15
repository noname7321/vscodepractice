import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

#method 1:subplot2grid
plt.figure(num=1,figsize=(10,5))
plt.subplot2grid((3,3),(0,0),colspan=3,rowspan=1) # create a subplot that spans across all 3 columns in the first row
plt.plot([0,1],[0,1]) # plot a line from (0,0) to (1,1)
plt.subplot2grid((3,3),(1,0),colspan=2) # create a subplot that spans across the first two columns in the second row
plt.plot([0,1],[1,0]) # plot a line from (0,1) to (1,0)
plt.subplot2grid((3,3),(1,2),rowspan=2) # create a subplot that spans across the last column in the second and third rows
plt.plot([0,1],[0.5,0.5]) # plot a horizontal line at y=0.5
plt.subplot2grid((3,3),(2,0)) # create a subplot in the first column of the third row
plt.plot([0.5,0.5],[0,1]) # plot a vertical line at x=0.5
plt.subplot2grid((3,3),(2,1)) # create a subplot in the second column of the third row
plt.plot([0,1],[0.5,0.5]) # plot a horizontal line at y=0.5

#method 2:gridspec
plt.figure(num=2,figsize=(10,5))
gs=gridspec.GridSpec(3,3) # create a 3x3 grid specification
plt.subplot(gs[0,:]) # create a subplot that spans across all columns in the first row
plt.plot([0,1],[0,1]) # plot a line from (0,0) to (1,1)
plt.subplot(gs[1,:2]) # create a subplot that spans across the first two columns in the second row
plt.plot([0,1],[1,0]) # plot a line from (0,1) to (1,0)
plt.subplot(gs[1:,2]) # create a subplot that spans across the last column in the second and third rows
plt.plot([0,1],[0.5,0.5]) # plot a horizontal line at y=0.5
plt.subplot(gs[2,0]) # create a subplot in the first column of the third row'
plt.plot([0.5,0.5],[0,1]) # plot a vertical line at x=0.5
plt.subplot(gs[2,1]) # create a subplot in the second column of the third row
plt.plot([0,1],[0.5,0.5]) # plot a horizontal line at y=0.5

# method 3:easy to define structure
plt.figure(num=3,figsize=(10,5))
f,((ax11,ax12),(ax21,ax22))=plt.subplots(2,2,sharex=True,sharey=True) # create a 2x2 grid of subplots and unpack the axes objects
# sharex=True and sharey=True means that the x and y axes will be shared among all subplots, so they will have the same limits and ticks.
ax11.plot([0,1],[0,1]) # plot a line from (0,0) to (1,1) in the first subplot
ax12.plot([0,1],[1,0]) # plot a line from (0,1) to (1,0) in the second subplot
ax21.plot([0,1],[0.5,0.5]) # plot a horizontal line at y=0.5 in the third subplot
ax22.plot([0.5,0.5],[0,1]) # plot a vertical line at x=0.5 in the fourth subplot




plt.show()