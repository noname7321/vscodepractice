lst=[88,99,90,89,00,97,89]
lst1=[88,99,90,89,00,97,89]
lst2=[88,99,90,89,00,97,89]
for i in range(0,len(lst)):
    if lst[i] == 0:
        lst[i]+=2000
    else:
        lst[i]+=1900
print(lst)

for i in range(0,len(lst1)):
    if str(lst1[i])!='0':
        lst1[i]='19'+str(lst1[i])
    else:
        lst1[i] = '200' + str(lst1[i])
        # lst1[i] 初始为 int，不能用 += 直接与字符串拼接；需要先转换为字符串再赋值。
print(lst1)

for index,value in enumerate(lst2):
    if value == 0:
        lst2[index]+=2000
    else:
        lst2[index]+=1900
print(lst2)