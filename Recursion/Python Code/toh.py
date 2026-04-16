import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("toh.csv", header=None, names=["n", "time"])

plt.plot(data["n"], data["time"], marker="o", label="Tower of Hanoi")

plt.xlabel("Number of Disks (n)")
plt.ylabel("Time (microseconds)")
plt.title("Tower of Hanoi Time Complexity")

plt.legend()
plt.grid(True)
plt.show()