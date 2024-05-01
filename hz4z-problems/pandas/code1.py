import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

df = pd.Series(
    [
        5,
        20,
        45,
        80,
        125,
        180,
        245,
        320,
        405,
        500,
        605,
        720,
        845,
        980,
        1125,
        1280,
        1445,
        1620,
        1805,
        2000,
    ]
)

df.plot()
plt.show()
