import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

fig=plt.figure(num=1,figsize=(10,5))
x=[1,2,3,4,5,6,7]
y=[1,3,4,2,5,8,6]
left,bottom,width,height=0.1,0.1,0.8,0.8
ax1=fig.add_axes([left,bottom,width,height])
ax1.plot(x,y,'r') # plot the main line in red
ax1.set_title('main plot') # set the title of the main plot
ax1.set_xlabel('x') # set the x-axis label of the main plot
ax1.set_ylabel('y') # set the y-axis label of the main plot

left,bottom,width,height=0.2,0.5,0.3,0.3
ax2=fig.add_axes([left,bottom,width,height]) # create a smaller axes object
ax2.plot(y,x,'b') # plot the smaller line in blue
ax2.set_title('subplot') # set the title of the smaller plot
ax2.set_xlabel('y') # set the x-axis label of the smaller plot
ax2.set_ylabel('x') # set the y-axis label of the smaller plot

plt.axes([0.5,0.2,0.3,0.3]) # create another smaller axes object using plt.axes() function
plt.plot(y[::-1],x,'g') # plot another line in green
#sequence[start:stop:step]，其中 step=-1 表示按相反顺序取元素，结果是返回 y 的反序副本（不修改原序列）。
# 例如，如果 y=[1,3,4,2,5,8,6]，则 y[::-1] 将返回 [6,8,5,2,4,3,1]。
plt.title('subplot2') # set the title of the second smaller plot
plt.xlabel('y') # set the x-axis label of the second smaller plot
plt.ylabel('x') # set the y-axis label of the second smaller plot

plt.show()