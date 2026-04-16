import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("ball_problem.csv", header=None, names=["height", "time"])

plt.plot(data["height"], data["time"], marker="o", label="Ball Problem")

plt.xlabel("Height")
plt.ylabel("Time (nanoseconds)")
plt.title("Ball Problem Time Complexity")

plt.legend()
plt.grid(True)
plt.show()