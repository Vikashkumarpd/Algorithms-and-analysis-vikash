import matplotlib.pyplot as plt
import csv


def read_csv(filename):
    x = []
    y = []

    with open(filename, "r") as file:
        reader = csv.reader(file)
        for row in reader:
            x.append(int(row[0]))
            y.append(int(row[1]))

    return x, y



x1, y1 = read_csv("by_profit.csv")
x2, y2 = read_csv("by_ratio.csv")
x3, y3 = read_csv("bywt.csv")



plt.plot(x1, y1, marker='o', label="Taking maximum profit first")
plt.plot(x2, y2, marker='s', label="Maximum profit by ratio")
plt.plot(x3, y3, marker='^', label="Taking weight for maximum profit")



plt.title("knapsack")
plt.xlabel("size of array")
plt.ylabel("Profit")
plt.grid(True)

plt.legend()   

plt.show()