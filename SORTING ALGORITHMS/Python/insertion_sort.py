import pandas as pd
import matplotlib.pyplot as plt

best = pd.read_csv("insertion_best_case.csv")
worst = pd.read_csv("insertion_worst_case.csv")
avg = pd.read_csv("insertion_avg_case.csv")

plt.plot(best["n"], best["time"], marker="o", label="Best Case O(n)")
plt.plot(worst["n"], worst["time"], marker="o", label="Worst Case O(n^2)")
plt.plot(worst["n"], avg["time"], marker="o", label="Avg Case O(n^2)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Insertion Sort: Best vs Worst Case")

plt.legend()
plt.grid(True)
plt.show()