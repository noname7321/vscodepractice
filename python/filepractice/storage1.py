def my_write():
    lst=["第一行\n","第二行\n","第三行\n",'2','3','4','5']
    with open("123.csv","w",encoding="utf-8") as file:
        file.write(''.join(lst))#将列表中的字符串连接成一个字符串并写入文件
def my_read():
    with open("123.csv","r",encoding="utf-8") as file:
        content=file.read()
        lst=content.splitlines()#将字符串按行分割成列表
        print(lst)

def my_write_table():
    lst=[["姓名","年龄","性别"],["张三","20","男"],["李四","22","女"]]
    with open("345.csv","w",encoding="utf-8") as file:
        for row in lst:
            file.write(','.join(row)+'\n')#将每行的列表连接成字符串并写入文件

def my_read_table():
    with open("345.csv","r",encoding="utf-8") as file:
        content=file.read()
        rows=content.splitlines()#将字符串按行分割成列表
        table=[row.split(',') for row in rows]#将每行的字符串按逗号分割成列表
        print(table)

if __name__ == '__main__':
    my_write()
    my_read()
    my_write_table()
    my_read_table()
#''.join(lst)： join 是字符串的方法，
# 用来把一个可迭代对象（通常是字符串列表）中的所有元素连接成一个新的字符串，调用者字符串作为分隔符。
#在你的代码中： ''.join(lst) 用空字符串作为分隔符，
# 把 lst 中的各行（比如 "第一行\n" 等）连成一个整体字符串，然后 file.write() 写入文件。