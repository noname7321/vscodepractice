import requests,re
url= "https://www.bing.com"
response = requests.get(url)
response.encoding = "utf-8"
# if response returns 200, it means the request was successful
if response.status_code == 200:
    # print(response.text)
    chineses=re.findall(r'[\u4e00-\u9fff]+',response.text)
    print(chineses)
#(pattern:r'[\u4e00-\u9fff]+') is used to match Chinese characters in the text.
#  The range [\u4e00-\u9fff] covers the common Chinese characters in Unicode. 
# The re.findall() function is used to find all occurrences of Chinese characters in the response text and return them as a list.
url='https://www.baidu.com/img/PCtm_d9c8750bed0b3c7d089fa7d55720d6cf.png'
resp=requests.get(url)
with open('logo.png','wb') as file:
    file.write(resp.content)