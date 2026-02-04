def fibonacci(n):
    if n==1 or n==2:
        return 1
    else:
        return fibonacci(n-1)+fibonacci(n-2)
n = int(input("请输入一个正整数："))
print(fibonacci(n))