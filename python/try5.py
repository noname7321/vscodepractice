def my_write():
    file=open("test.txt","a",encoding="utf-8")
    file.write("hello world\n")
    file.write("你好，世界\n")
    file.seek(0)  # 将文件指针移动到文件开头
    file.close()

def my_read():
    file=open("test.txt","r",encoding="utf-8")
    content=file.read()
    content=file.read()  # 由于文件指针已经在文件末尾，所以再次读取会得到空字符串
    file.seek(0)  # 将文件指针移动到文件开头
    content=file.read(2)  # 读取前两个字符 
    print(content)
    file.close()

def my_write_list(file,lst):
    f=open(file,"a",encoding="utf-8")
    f.writelines(lst)
    f.close()

if __name__ == '__main__':
    my_write()
    lst=["第一行\n","第二行\n","第三行\n"]
    my_write_list("test.txt",lst)
    my_read()