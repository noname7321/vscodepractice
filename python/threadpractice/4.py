import threading
from threading import Thread,Lock
import time,os

ticket=50

lock_obj=Lock()

def sale_ticket():
    global ticket
    for i in range(100):
        if ticket>0:
            print(f"线程 {threading.current_thread().name} 正在出售第 {ticket} 张票，线程ID: {threading.get_ident()}")
            ticket -= 1
        time.sleep(0.5)

# 以上代码存在一个问题：多个线程同时访问和修改共享变量 'ticket'，可能会导致数据不一致的情况发生。
# 例如，如果两个线程同时检查 'ticket > 0' 条件并且都认为票数足够，那么它们可能会同时出售同一张票，导致 'ticket' 的值被错误地减少两次。
# 这种情况被称为“竞态条件” (race condition)。
# 为了解决这个问题，我们可以使用线程同步机制，例如锁 (Lock) 来确保同一时间只有一个线程能够访问和修改 'ticket' 变量。
def sale_ticket_safe():
    global ticket
    for i in range(100):
        lock_obj.acquire() # 获取锁
        if ticket>0:
            print(f"线程 {threading.current_thread().name} 正在出售第 {ticket} 张票，线程ID: {threading.get_ident()}")
            ticket -= 1
        time.sleep(0.5)
        lock_obj.release() # 释放锁
# 在上面的代码中，我们使用了一个锁对象 'lock_obj' 来保护对 'ticket' 变量的访问。
# 在每次访问 'ticket' 之前，线程会先获取锁，确保只有一个线程能够进入临界区 (critical section) 来检查和修改 'ticket' 的值。
# 完成操作后，线程会释放锁，让其他线程有机会访问 'ticket'。这样可以避免竞态条件，确保程序的正确性。

if __name__ == "__main__":
    for i in range(3):
        t=Thread(target=sale_ticket_safe,name=f"Thread-{i+1}")
        t.start()
    

