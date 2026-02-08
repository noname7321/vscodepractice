import numpy as np
import matplotlib.pyplot as plt

n1=plt.imread('logo.png')
print(type(n1))
n1 = n1[..., :3] 
#print(n1)
# the higest level of the array represents the rows of the image,
# the second level represents the columns of the image, 
# and the third level represents the color channels (red, green, blue) of each pixel in the image. 
# Each pixel's color is represented as a combination of these three color channels, 
# with values typically ranging from 0 to 255 for each channel.
n2=np.array([0.299,0.587,0.114])
x=np.dot(n1,n2)
plt.imshow(x,cmap='gray')
plt.axis('off')
plt.show()