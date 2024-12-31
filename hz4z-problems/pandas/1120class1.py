import pandas as pd

df = pd.read_csv("1120a.csv")


def getd(x):
    df1 = df[df.楼道编号 == x]
    df1 = df1.groupby("时").sum()
    df1 = df1.sort_values("灯状态", ascending=False)
    print(df1)
    print(df1.index)
    return df1.index[0]


d = {}
for i in range(1, 6):
    t = getd(i)
    print(i, t)
