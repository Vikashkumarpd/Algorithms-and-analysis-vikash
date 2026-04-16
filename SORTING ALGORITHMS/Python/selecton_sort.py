import pandas as pd
import matplotlib.pyplot as plt

best = pd.read_csv("selection_best_case.csv")
worst = pd.read_csv("selection_worst_case.csv")
avg = pd.read_csv("selection_avg_case.csv")

plt.plot(best["n"], best["time"], marker="o", label="Best Case O(n^2)")
plt.plot(worst["n"], worst["time"], marker="o", label="Worst Case O(n^2)")
plt.plot(avg["n"], avg["time"], marker="o", label="Average Case O(n^2)")

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Selection Sort: Best vs Worst vs Average Case")

plt.legend()
plt.grid(True)
plt.show()