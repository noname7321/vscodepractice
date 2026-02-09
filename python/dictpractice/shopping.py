total_price = 0
dict={
    1:{"name":"苹果","price":5},
    2:{"name":"香蕉","price":3},
    3:{"name":"橘子","price":4},
    4:{"name":"西瓜","price":10},
    5:{"name":"葡萄","price":8}}
while(True):
    if input("请输入要购买的商品编号，会自动放入购物车").lower() == "q":
        print(f"购物车已解算，总价格为{total_price}，欢迎下次光临")
        break
    item_number = int(input("请输入商品编号（1-5）："))
    quantity = int(input("请输入购买数量："))
    total_price += dict[item_number]["price"] * quantity