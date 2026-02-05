lst=[]
s=input("please input a string:")
def get_find(lst,s):
    for item in lst:
        if item==s:
            return True
    return False