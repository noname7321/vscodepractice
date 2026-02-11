from threading import Thread

a=100

def add():
    print('add function is called')
    global a
    a+=30
    print(f'the value of a is {a}')
    print('add function is completed')

def sub():
    print('sub function is called')
    global a
    a-=50
    print(f'the value of a is {a}')
    print('sub function is completed')

if __name__ == '__main__':
    print('main thread is started')
    print(f'the value of a is {a}')
    t1=Thread(target=add)
    t2=Thread(target=sub)
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print('main thread is completed')
    print(f'the value of a is {a}')
# different threads are modifying the same variable 'a' without any synchronization mechanism, which can lead to a race condition
# The output of the above code may vary each time you run it because the order of execution of the threads is not guaranteed. 
# The value of 'a' may be different depending on whether the 'add' or 'sub' function executes first.