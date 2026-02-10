from multiprocessing import Queue

if __name__ == "__main__":
    q=Queue(3) #创建一个容量为3的队列
    print('队列是否为空：',q.empty()) #检查队列是否为空,True
    print('队列是否已满：',q.full())   #检查队列是否已满,False
    q.put(1)  #向队列中添加元素1
    q.put(2)  #向队列中添加元素2
    print('队列是否为空：',q.empty()) #检查队列是否为空,False
    print('队列是否已满：',q.full())   #检查队列是否已满,False
    q.put(3)  #向队列中添加元素3
    print('队列是否为空：',q.empty()) #检查队列是否为空,False
    print('队列是否已满：',q.full())   #检查队列是否已满,True
    print('队列中的元素个数：',q.qsize()) #获取队列中的元素个数

    print('从队列中取出一个元素：',q.get()) #从队列中取出一个元素，先进先出,1
    print('队列中的元素个数：',q.qsize()) #获取队列中的元素个数,2

    q.put_nowait(4) #向队列中添加元素4,不阻塞
    print('队列中的元素个数：',q.qsize()) #获取队列中的元素个数,3
    q.put(5)#向队列中添加元素5,阻塞直到有空间
    print('队列中的元素个数：',q.qsize()) #获取队列中的元素个数,3

    q.put("6",timeout=5) #向队列中添加元素6,阻塞直到有空间,如果5秒内没有空间则抛出异常
    
    if not q.empty():
        for i in range(q.qsize()):
            print('从队列中取出一个元素：',q.get()) #从队列中取出一个元素，先进先出,2,3,4
      