import pandas as pd
data = {
    'Name': ['Taksh', 'Laksh', 'Krrish', 'Abhay'],
    'Height': [170, 165, 180, 155],
    'Qualification': ['Bachelor', 'Master', 'PhD', 'Bachelor']
}
df = pd.DataFrame(data)
print(df)

address_list = ['Mumbai', 'Delhi', 'Hyderabad', 'Prayagraj']
df['Address'] = address_list
print(df)

df.insert(1, 'Age', [20, 20, 20, 20])
print(df)
