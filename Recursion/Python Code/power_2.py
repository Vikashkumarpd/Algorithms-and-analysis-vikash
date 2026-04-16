import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("power_rec.csv", header=None, names=["n", "time"])

plt.plot(data["n"], data["time"], marker="o", label="Power Function")

plt.xlabel("Power (n)")
plt.ylabel("Time (nanoseconds)")
plt.title("Recursive Power Function Time Complexity")

plt.legend()
plt.grid(True)
plt.show()