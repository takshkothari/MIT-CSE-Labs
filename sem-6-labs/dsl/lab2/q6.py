import pandas as pd
import numpy as np
data = {
    'Name': ['Annie', 'Diya', 'Charles', 'James', 'Emily'],
    'Quiz_1/10': [8.0, 9.0, 7.5, 8.5, 6.5],
    'Insem_1/15': [11.0, 14.0, 14.5, 13.0, 12.5],
    'Quiz_2/10': [9.5, 6.5, 8.5, 9.0, 9.0],
    'Insem_2/15': [12.5, 13.5, 14.5, 15.0, 13.0]
}
df = pd.DataFrame(data)
df['Total'] = df.sum(axis=1, numeric_only=True)
me = ['NaN']
me[1:] = df.iloc[:,1:].mean()
df.loc[len(df)] = me
print(df)
