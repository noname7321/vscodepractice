import copy

print("=== 赋值：可变对象共享 ===")
a = [1, 2, 3]
b = a
b.append(4)
print(a)          # [1, 2, 3, 4]
print(b)          # [1, 2, 3, 4]
print(a is b)     # True

print("\n=== 赋值：不可变对象重新绑定 ===")
a = 1
b = a
b = 2
print(a)          # 1
print(b)          # 2
print(a is b)     # False

print("\n=== 浅拷贝：外层新、内层共享（可变子对象）===")
original = [[1, 2], [3, 4]]
shallow = original[:]  # 或 copy.copy(original)
print(original is shallow)       # False（外层不同）
print(original[0] is shallow[0]) # True（内层同一对象）
shallow[0].append(99)
print(original)  # [[1, 2, 99], [3, 4]]
print(shallow)   # [[1, 2, 99], [3, 4]]

print("\n=== 浅拷贝：元素不可变时通常安全 ===")
a = [1, 2, 3]
b = a[:]
b[0] = 99
print(a)  # [1, 2, 3]
print(b)  # [99, 2, 3]

print("\n=== 深拷贝：外层与内层都独立 ===")
original = [[1, 2], [3, 4]]
deep = copy.deepcopy(original)
print(original is deep)         # False
print(original[0] is deep[0])   # False
deep[0].append(99)
print(original)  # [[1, 2], [3, 4]]
print(deep)      # [[1, 2, 99], [3, 4]]