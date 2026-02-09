s=input("Enter a string: ")
for ls in s:
    if 'A'<=ls<='Z':
        print(chr(ord(ls)+32),end='')
         # ord translate char to ASCII code, chr translate ASCII code to char
         # add 32 to uppercase letter ASCII code to get lowercase letter ASCII code
    elif 'a'<=ls<='z':
        print(chr(ord(ls)-32),end='')
        # subtract 32 to lowercase letter ASCII code to get uppercase letter ASCII code
    else:
        print(ls,end='')
        # non-alphabetic characters remain unchanged