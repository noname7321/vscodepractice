def logger(func):
    def wrapper(*args, **kwargs):
        print ('logging execution')
        func(*args, **kwargs)
        print('Done logging')
    return wrapper# A decorator must return a callable;
    #here, it returns wrapper

@logger # @ will automatically apply the decorator to the function below
def sample():
    print('-- Inside sample function --')
    #sample = logger(sample)，被装饰后的 sample 指向 wrapper 函数
sample() 