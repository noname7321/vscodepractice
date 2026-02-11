from queue import Queue
from threading import Thread
import time
import threading    

class producer(Thread):
    def __init__(self,queue):
        super().__init__()
        self.queue=queue
    def run(self):
        for i in range(5):
            print(f"生产者 {self.name} 生产了 {i}，线程ID: {self.ident}")
            self.queue.put(i)
            time.sleep(0.5)

class consumer(Thread):
    def __init__(self,queue):
        super().__init__()
        self.queue=queue
    def run(self):
        for i in range(5):
            item=self.queue.get()
            print(f"消费者 {self.name} 消费了 {item}，线程ID: {self.ident}")
            time.sleep(0.5)

if __name__ == "__main__":
    print(f"主线程 {threading.current_thread().name} 开始运行，线程ID: {threading.get_ident()}")
    q=Queue()
    p=producer(queue=q)
    c=consumer(queue=q)
    p.start()
    c.start()
    p.join()
    c.join()
    print(f"主线程 {threading.current_thread().name} 结束运行，线程ID: {threading.get_ident()}")