import pandas as pd
data = pd.read_csv('haberman.csv')
print(data.head())
print(data.shape)

import matplotlib.pyplot as plt
plt.plot(data('year','age'))
