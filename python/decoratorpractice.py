import time
from functools import wraps
# @decorator equals to func = decorator(func)
# func = decorator(func) 的意思是：把原函数 func 交给 decorator，
# 返回一个“增强后的新函数”，再把它赋回到同名变量 func。
# 这样调用 func() 时，其实是在调用“增强后的函数”。
# 实现在不修改原函数代码的情况下，
# 为函数/方法增加额外功能”的语法糖，本质是高阶函数
def timing(func):#接收一个函数func作为参数，返回一个新函数wrapper
    @wraps(func) #用来把原函数的元信息复制到 wrapper 上
    def wrapper(*args, **kwargs):#接收任意参数
        start = time.time()
        result = func(*args, **kwargs)# *args 会把所有位置参数收集成一个元组
                                    # **kwargs 会把所有关键字参数收集成一个字典
        cost = time.time() - start
        print(f"{func.__name__} took {cost:.4f}s")
        return result
    return wrapper

@timing # equals to slow_add = timing(slow_add) 
def slow_add(a, b):
    time.sleep(0.2)
    return a + b

print(slow_add(3, 5))

# ===== 手写等价写法（不使用 @） =====
# 1) 先定义原函数
def slow_add_plain(a, b):
    time.sleep(0.2)
    return a + b

# 2) 用装饰器包起来，得到增强后的新函数
slow_add_plain = timing(slow_add_plain)

# 3) 调用时，其实是在调用 wrapper
print(slow_add_plain(3, 5))
