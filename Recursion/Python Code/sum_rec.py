import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("sum_rec.csv", header=None, names=["n", "time"])

plt.plot(data["n"], data["time"], marker="o", label="Recursive Sum")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Recursive Sum Function Time Complexity")

plt.legend()
plt.grid(True)
plt.show()