import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
df=pd.read_csv('data.csv')
#print(df)
plt.rcParams['font.sans-serif']=['SimHei']
plt.figure(figsize=(10,6))

labels=df['城市']
values=df['人口数量']
plt.pie(values,labels=labels,autopct='%1.1f%%',startangle=90)
plt.title('中国主要城市人口分布')
plt.axis('equal')
plt.show()