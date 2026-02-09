import prettytable as pt

def show_tickets(row_num):
    tb=pt.PrettyTable()#创建表格对象
    tb.field_names=['行号','座位1','座位2','座位3','座位4','座位5']#设置表头
    for i in range(1,row_num+1):
        lst =[f"第{i}行",f"第{i}行座位1"+"有票",f"第{i}行座位2",f"第{i}行座位3",f"第{i}行座位4",f"第{i}行座位5"]
        tb.add_row(lst)
    print(tb)

if __name__ == '__main__':
    show_tickets(5)