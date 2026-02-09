from pathlib import Path
out_path = Path(__file__).parent / 'a.txt'
file=open(out_path,'w+')
lst=['apple','banana','cherry']
file.writelines(lst)# write list to file
file.seek(0)
for item in file:
    print(item) #
file.close()