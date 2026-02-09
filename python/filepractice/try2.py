import os
import os.path
from pathlib import Path

creath_path = Path(__file__).parent

def mkdirs(path,num):
    try:
        for item in range(1,num+1):
            os.mkdir(path)/str(item)
    except FileExistsError as e:
        print("文件夹已存在",e)

if __name__ == "__main__":
    num=eval(input("请输入要创建的文件夹数量："))
    mkdirs(creath_path,num)