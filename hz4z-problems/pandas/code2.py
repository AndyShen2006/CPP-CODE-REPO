import matplotlib.pyplot as plt
import pandas as pd

data = [["Google", 10, 12], ["Runoob", 12, 14], ["Google", 13, 15]]

df = pd.DataFrame(data, columns=["Site", "Age1", "Age2"])

# print(df["Google"])

pd.group_by("Site")["Age1"].sum()
# df.plot()
# plt.show()
