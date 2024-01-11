import pandas as pd
df1 = pd.DataFrame({ 'Name': ['Ram', 'Diya', 'Chandan', 'James', 'Alice'] })
data = {
    'Math': [80.0, 90.0, 77.5, 87.5, 86.5],
    'Physics': [81.0, 94.0, 74.5, 83.0, 82.5],
    'Chemistry': [91.5, 86.5, 85.5, 90.0, 91.0],
    'Bio': [82.5, 83.5, 84.5, 85.0, 93.0]
}
df2 = pd.DataFrame(data)
df_new = pd.concat([df1, df2], axis=1)
df_new['Total'] = df_new.sum(axis=1, numeric_only=True)
print(df_new)