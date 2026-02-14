import matplotlib.pyplot as plt
import numpy as np
x=np.linspace(-3,3,50)
y =0.1*x
plt.figure(num=1,figsize=(10,5))
plt.plot(x, y, linewidth=10, zorder=1) # keep the line below tick labels
plt.ylim(-2, 2)
ax= plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data', 0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data', 0))


for label in ax.get_xticklabels() + ax.get_yticklabels(): 
    # get_xticklabels() 和 get_yticklabels() 分别返回 x 轴和 y 轴的所有刻度标签对象的列表。
    # 通过加号连接这两个列表，我们可以一次性遍历所有的刻度标签。
    label.set_fontsize(12) # 设置字体大小为 12
    # 更明显的 bbox：加浅色背景与灰色边框，并提升 zorder 以防被线条遮挡
    label.set_bbox(dict(boxstyle='round,pad=0.35', facecolor='#fff4cc', edgecolor='#888888', linewidth=0.8, alpha=0.95))
    label.set_zorder(10) # 提升 zorder 以确保标签在其他元素之上显示
    label.set_clip_on(False)
    # set_bbox() 方法为每个标签设置一个背景框；增加 pad/boxstyle 可提供内边距并改善显示。

plt.show()