lst=[]
for i in range(3):
    item=input(f"请输入第{i+1}个商品编号和名称：")
    lst.append(item)
flag = True
shopcart = []
while(flag):
    item=input("请输入要购买的商品编号，输入q退出：")
    if item.lower() == "q":
        flag = False
    for i in range(len(lst)):#for items in lst:
        if lst[i][0:4] == item:# items[0:4] == item:
            print(f"已将{lst[i][4:]}加入购物车")
            shopcart.append(lst[i][4:])
            break
        else:
            if i == len(lst)-1:
                print("商品编号不存在，请重新输入")
print(f"您购买的商品有：{shopcart}")
print("购物结束，欢迎下次光临")