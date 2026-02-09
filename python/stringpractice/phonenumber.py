s=set()
for i in range(2):
    info=input(f"请输入第{i+1}个姓名和电话号码：")
    s.add(info)
for item in s:
    name=item.split()[0]
    try:
        phone=item.split()[1]
    except Exception:
        phone="无"
    print(f"{name}的电话号码是{phone}")