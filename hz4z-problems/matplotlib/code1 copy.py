import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0, 10, 1000)
y = np.sin(x)

plt.figure(figsize=(4, 4))
plt.plot(x, y, label="sin(x)", color="red", linewidth=2)

plt.xlabel("Time(s)")
plt.ylabel("Volt")

plt.title("Volt-Time Graph")
plt.ylim(-2, 2)
plt.legend()
plt.show()
