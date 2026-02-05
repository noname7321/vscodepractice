def double(x):
    return x * 2
def triple(x):
    return x * 3  
def calculate(func, value):
    return func(value)
result1 = calculate(double, 5)
result2 = calculate(triple, 5)
print("Double of 5 is:", result1)
print("Triple of 5 is:", result2)

def get_multiple_func(n):
    def multiply(x):
        return x * n
    return multiply
double_func = get_multiple_func(2)
triple_func = get_multiple_func(3)
print("Double of 7 is:", double_func(7))
print("Triple of 7 is:", triple_func(7))

def dec(f):
    return 1
@dec # equals to double_value = dec(double_value)
def double_value(x):
    return x * 2
print(double_value) 
# This will print 1 because the decorator replaces the function

import time
def timeit(f):
    def wrapper(x):
        start = time.time()
        result = f(x)
        end = time.time()
        print(f"Execution time: {end - start} seconds")
        return result
    return wrapper
@timeit # equals to my_func = timeit(my_func) = wrapper
def my_func(x):
    time.sleep(x)

my_func(2)  # This will print the execution time of my_func

@timeit
def other_func(x):
    return x*2
print(other_func(5)) 
 # This will print the execution time and the result of other_func