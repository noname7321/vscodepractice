import matplotlib.pyplot as plt
import numpy as np

# image data
a=np.array([[0.313726, 0.419608, 0.505882],
            [0.741176, 0.858824, 0.952941],
            [0.176471, 0.282353, 0.364706]]).reshape(3,3) 
# create a 3x3 array of RGB values,reshape means to change the shape of the array to 3 rows and 3 columns,
# each row corresponds to a pixel and contains the RGB values for that pixel,

# for the value of interpolation, see https://matplotlib.org/stable/gallery/images_contours_and_fields/interpolation_methods.html
plt.imshow(a,interpolation='nearest',cmap=plt.cm.bone,origin='lower') # display the array as an image
# interpolation='nearest' means no interpolation, so the image will be displayed as a grid of colored squares,
# cmap=plt.cm.bone specifies the colormap to use for mapping the RGB values to colors,
# origin='lower' means the [0,0] index of the array will be at the lower left corner of the image
# upper left corner is the default origin, so we set origin='lower' to move it to the lower left corner

plt.colorbar(shrink=0.9) # add a colorbar to the image,shrink=0.9 means to shrink the colorbar to 90% of its original size

plt.xticks(()) # remove x-axis ticks
plt.yticks(()) # remove y-axis ticks
plt.show() # display the plot