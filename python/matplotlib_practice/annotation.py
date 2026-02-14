from matplotlib import pyplot as plt
import numpy as np

x=np.linspace(0,5,11) # start from 0 to 5, with 11 evenly spaced points
y=x**2
ax = plt.gca()
ax.spines['bottom'].set_position(('data', 0))
ax.spines['top'].set_color('none')
ax.spines['right'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
plt.figure(num=1,figsize=(10,5)) # num=2 means this is the third figure,

plt.plot(x,y,label='x^2') # plot x^2
plt.legend() # show the legend
# annotation
x0=2
y0=x0**2
plt.scatter(x0,y0,s=100,color='red') 
# mark the point (x0,y0),scatter is used to plot individual points, 
# s=100 sets the size of the point to 100, color='red' sets the color of the point to red
plt.plot([x0,x0],[0,y0],color='black',linewidth=1,linestyle='--')
# plot a dashed vertical line from (x0,0) to (x0,y0) to highlight the local maximum at (2,4)
# 默认情况下 Matplotlib 把 x 轴的可见线（bottom spine）放在图框底部（axes‑coordinates），而你画的虚线是按 数据坐标 y=0 画的 —— 两者位置不一定重合，所以看起来“未相交”。
plt.annotate('point', xy=(x0,y0), xytext=(3,10), arrowprops=dict(arrowstyle='->', facecolor='green', connectionstyle='arc3,rad=0.4')) 
# add an annotation with an arrow pointing to the local maximum at (2,4)
# xy is the point to annotate, xytext is the position of the text, arrowprops is a dictionary of properties for the arrow
# arrowstyle='->' means the arrow will have a head, facecolor='green' sets the color of the arrow to green, 
# connectionstyle='arc3,rad=0.4' makes the arrow curved with a radius of 0.4

# plt.annotate('point', xy=(x0,y0),xycoords='data', xytext=(+30,+10),textcoords='offset points'
#              , arrowprops=dict(arrowstyle='->', facecolor='green', connectionstyle='arc3,rad=0.4')) 

plt.text(1,24,r'$ this\ is\ some\ text,\mu=100,\ \sigma=15$',fontdict={'size':10,'color':'red'})

plt.show()