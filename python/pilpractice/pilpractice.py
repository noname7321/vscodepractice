from PIL import Image, ImageFilter
im=Image.open("logo.png")
# print(type(im),im)
# <class 'PIL.PngImagePlugin.PngImageFile'> <PIL.PngImagePlugin.PngImageFile image mode=RGBA size=540x258 at 0x1AD7F65EBA0>
r,g,b=im.split()
print(type(r),r)
# <class 'PIL.Image.Image'> <PIL.Image.Image image mode=L size=540x258 at 0x1AD7F65EFA0>
print(type(g),g)
# <class 'PIL.Image.Image'> <PIL.Image.Image image mode=L size=540x258 at 0x1AD7F65EFD0>
print(type(b),b)
# <class 'PIL.Image.Image'> <PIL.Image.Image image mode=L size=540x258 at 0x1AD7F65EFD0>
im2=Image.merge("RGB",(r,g,b))

