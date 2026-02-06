a = 1
b = a  # b 指向与 a 相同的整数对象 1
b = 2  # 重新绑定 b 到另一个整数对象 2（并没有修改原来的 1）
print(a)  # 1
print(b)  # 2
print(a is b)  # False（除非两个名字都指向同一个对象）

a = [1, 2, 3]
b = a       # b 和 a 指向同一个列表对象
b.append(4) # 就地修改该列表对象
print(a)    # [1, 2, 3, 4]
print(b)    # [1, 2, 3, 4]
print(a is b)  # True，表示同一个对象