import os,time
from multiprocessing import Process, current_process

def sub_process1(name):
    print(f"子进程 {current_process().name} 开始运行，PID: {os.getpid()}, 其父进程PID: {os.getppid()}")
    time.sleep(1)
    print(f"子进程 {current_process().name} 结束运行，PID: {os.getpid()}")

def sub_process2(name):
    print(f"子进程 {current_process().name} 开始运行，PID: {os.getpid()}, 其父进程PID: {os.getppid()}")
    time.sleep(2)
    print(f"子进程 {current_process().name} 结束运行，PID: {os.getpid()}")

if __name__ == "__main__":
    print(f"主进程 {current_process().name} 开始运行，PID: {os.getpid()}")
    
    p1 = Process(target=sub_process1, name="SubProcess1", args=("SubProcess1",))
    p2 = Process(target=sub_process2, name="SubProcess2", args=("SubProcess2",))
    
    p1.start()
    p2.start()
    
    p1.join() #等待子进程1结束
    p2.join() #等待子进程2结束
    
    print(f"主进程 {current_process().name} 结束运行，PID: {os.getpid()}")