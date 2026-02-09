import random
def find_lst_max(lst):
    if not lst:
        return None  # 如果列表为空，返回 None
    # max_value = lst[0]
    # for item in lst:
    #     if item > max_value:
    #         max_value = item
    # return max_value

    # return max(lst)  # 使用内置的 max 函数返回最大值
    
    lst.sort()
    return lst[-1]  # 返回排序后列表的最后一个元素，即最大值

lst=[random.randint(1, 100) for _ in range(10)]
print("列表内容:", lst)
max_value = find_lst_max(lst)
print("列表中的最大值是:", max_value)