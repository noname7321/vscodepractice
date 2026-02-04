# print("µ".encode("ascii", errors="ignore"))            # b'' (丢弃不可编码字符)
# print("µ".encode("ascii", errors="replace"))           # b'?' (用问号替换)
# print("€".encode("ascii", errors="xmlcharrefreplace")) # b'&#8364;'
# print("€".encode("ascii", errors="backslashreplace"))  # b'\\u20ac' 或类似转义表示
# s = "banana"
# result = "".join(set(s))#
# print(result)# # 输出字符串中不重复的字符，顺序不定


# import re
# text = "cat, car, cut"
# pattern = r"cat$"           # '$' 要求在结尾
# print(bool(re.search(pattern, text)))  # True -> 文本结尾是 cat

# text = "Hello123"
# pat = r"Hello13"              # 期望在开头匹配 'Hello'
# res = re.match(pat, text)    # match 从开头匹配
# try:
#     print(res.group())
# except AttributeError:
#     print('no match (res is None)')

# text = "a.B"
# text1="a.b"
# print(bool(re.search(r"b", text, flags=re.I)))  # True -> 忽略大小写
# print(bool(re.search(r"a.b", text1)))  

# csv = "a,b,c,d"
# print(csv.split(","))      # ['a', 'b', 'c', 'd']
# print(csv.split(",", 2))   # ['a', 'b', 'c,d']
# txt="one1two2three3four4"
# print(txt.split("2"))        # ['one1two', 'three3four4']

# import re

# # 匹配以 13 开头且第三位为 4-9 的 11 位手机号码（示例）
# pattern = r'13[4-9]\d{8}'#后面是8位就可以了

# lst = ['13809876543', '15109876543', '13278965439', '15912345665', '13198765432']

# for item in lst:
#     match = re.match(pattern, item)
#     if match is not None:
#         print(match.group())

items = ['a', 'b', 'c']
print(list(enumerate(items, 2))) 

lines = ["第一行", "第二行", "第三行"]
for line_num, line in enumerate(lines, start=1):
    print(f"行 {line_num}: {line}")