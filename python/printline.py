for i in range(1,6):
    for j in range(1,i+1):
        print('*',end='')
    print()
print()
for i in range(6,1,-1):
    for j in range(1,i):
        print('*',end='')
    print()
print()
for i in range(1,6):
    for k in range(1,6-i):
        print(' ',end='')    
    for j in range(1,2*i):
        print('*',end='')
    # for k in range(1,5-i):
    #     print(' ',end='')  
    print()
print()

def print_diamond(n):
    """打印菱形；若 n 为偶数则自动加 1 变为奇数行数。"""
    if n <= 0:
        return
    if n % 2 == 0:
        n += 1
    mid = n // 2
    # 上半部分（含中间行）
    for i in range(mid + 1):
        spaces = mid - i
        stars = 2 * i + 1
        print(' ' * spaces + '*' * stars)
    # 下半部分
    for i in range(mid - 1, -1, -1):
        spaces = mid - i
        stars = 2 * i + 1
        print(' ' * spaces + '*' * stars)


if __name__ == '__main__':
    try:
        rows = int(input('输入菱形行数（奇数，若为偶数将自动+1）: '))
    except Exception:
        rows = 10

    print()
    print_diamond(rows)
    print()
