import matplotlib.pyplot as plt
import pandas as pd

data = [["Google", 10, 12], ["Runoob", 12, 14], ["Google", 13, 15]]

df = pd.DataFrame(data, columns=["Site", "Age1", "Age2"])

# print(df["Google"])

df1 = df.groupby("Site").sum()
df1.sort_values("Age1")
print(df)
print(df.index[0])
# df.plot()
# plt.show()
