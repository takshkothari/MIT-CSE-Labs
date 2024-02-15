import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_excel('german.xlsx', engine='openpyxl')

plt.scatter(df['CreditAmount'], df['DurationOfCreditInMonths'])
plt.show()