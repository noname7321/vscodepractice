print('abc_pkg package is imported')
print('here is init.py')
#1. 为什么能运行了？（视角的降级）
# 当你直接运行 main1.py 时，Python 把当前文件夹（abc_pkg 目录）加到了搜索路径。

# 修改前 (import abc_pkg.my_abc)：Python 在当前目录下找叫 abc_pkg 的东西，
# 找不到（因为它就在那个文件夹里面），所以报错。

# 修改后 (import my_abc)：Python 在当前目录下直接找 my_abc.py，直接找到了，就像找邻居一样简单。
# 2. 为什么 __init__.py 没运行？（身份的丢失）
# __init__.py 的作用是初始化一个包。只有当你把这个文件夹当作一个“包”来导入时，它才会运行。

# 在这种运行方式下：
# Python 并没有意识到 abc_pkg 是一个包。
# 对它来说，abc_pkg 仅仅是存放代码的一个普通文件夹（也就是 sys.path 的一部分）。
# 你导入的是 my_abc 这个独立模块，而不是 abc_pkg.my_abc 这个包内成员。