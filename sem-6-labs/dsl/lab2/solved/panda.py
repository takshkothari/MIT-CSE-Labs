# Introduction to PANDAS

import pandas as pd
import numpy as np
s=pd.Series([3,9,-2,10,5])
print(s.sum())
print(s.min())
print(s.max())

# Creating a Data Frame
import pandas as pd
data = [['Dinesh',10],['Nithya',12],['Raji',13]]
df = pd.DataFrame(data,columns=['Name','Age'])
print(df)

# Indexed Data Frame
data = {'Name':['Kavitha', 'Sudha', 'Raju','Vignesh'],'Age':[28,34,29,42]}
df = pd.DataFrame(data, index=['rank1','rank2','rank3','rank4'])
print(df)

# Creating a DataFrame using Dictionary
df1=pd.DataFrame({'A':pd.Timestamp('20130102'), 'B':np.array([3]*4,dtype='int32'), 'C':pd.Categorical(['Male','Female','Male','Female'])})
print(df1)
print(df1.shape)
print(df1.dtypes)
print(df1.head())
print(df1.tail())
print(df.describe())
print(df.T)