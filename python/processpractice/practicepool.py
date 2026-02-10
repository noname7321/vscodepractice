from multiprocessing import Pool
import time,os

def task(name):
    print(f"子进程 {name} 开始运行，PID: {os.getpid()}, 其父进程PID: {os.getppid()}")
    time.sleep(1)
    print(f"子进程 {name} 结束运行，PID: {os.getpid()}")

if __name__ == "__main__":
    start=time.time()
    print(f"主进程 {os.getpid()} 开始运行,时间: {time.strftime('%H:%M:%S', time.localtime())}")
    p=Pool(5) #创建一个进程池，最多同时运行5个子进程
    for i in range(15):
        #p.apply_async(task,args=(f"SubProcess{i+1}",)) #异步执行任务
        p.apply(task,args=(f"SubProcess{i+1}",)) #同步执行任务，等待任务完成后才继续执行下一行代码

    p.close() #关闭进程池，表示不再添加新的进程
    p.join()  #等待进程池中的所有子进程执行完毕
    end=time.time()
    print(f"主进程 {os.getpid()} 结束运行,时间: {time.strftime('%H:%M:%S', time.localtime())}")
    print(f"总耗时: {end-start} 秒")