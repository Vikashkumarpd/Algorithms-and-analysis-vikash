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


# Read ternary search files
x1, y1 = read_csv("ternary_search_worst.csv")
x2, y2 = read_csv("ternary_search_best.csv")
x3, y3 = read_csv("ternary_search_avg.csv")


# Plot graphs
plt.plot(x1, y1, marker='o', label="Worst case")
plt.plot(x2, y2, marker='s', label="Best case")
plt.plot(x3, y3, marker='^', label="Average case")


# Labels
plt.title("Ternary Search Performance")
plt.xlabel("Size of Array")
plt.ylabel("Time (nanoseconds)")
plt.grid(True)

plt.legend()

plt.show()