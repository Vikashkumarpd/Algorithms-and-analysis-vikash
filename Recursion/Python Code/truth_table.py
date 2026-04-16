import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("Truth_table.csv", header=None, names=["n", "time"])

plt.plot(data["n"], data["time"], marker="o", label="Truth Table Generation")

plt.xlabel("Number of Variables (n)")
plt.ylabel("Time (nanoseconds)")
plt.title("Truth Table Generation Time Complexity")

plt.legend()
plt.grid(True)
plt.show()