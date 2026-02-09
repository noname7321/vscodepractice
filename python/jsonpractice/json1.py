import json
lst=[{'name':'Alice','age':25,'city':'London'}
     ,{'name':'Bob','age':30,'city':'New York'}
     ,{'name':'Charlie','age':35,'city':'San Francisco'}]
json_str=json.dumps(lst, ensure_ascii=False, indent=4)  # lst -> json_str 
# ensure_ascii=False to support non-ASCII characters, indent=4 for readability
print(type(json_str))
print(json_str)

lst2=json.loads(json_str) # json_str -> lst2
print(type(lst2))
print(lst2)

from pathlib import Path

out_path = Path(__file__).parent / 'data.json'
with open(out_path, 'w', encoding='utf-8') as f:
    json.dump(lst,f,ensure_ascii=False,indent=4) # lst -> file
print(f'Wrote file: {out_path}')
with open(out_path, 'r', encoding='utf-8') as f:
    lst3=json.load(f) # file -> lst3
print(type(lst3))
print(lst3)