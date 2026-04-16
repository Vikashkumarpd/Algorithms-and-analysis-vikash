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


# Read all three files
xW, yW = read_csv("quick_sortW.csv")
xB, yB = read_csv("quick_sortB.csv")
xA, yA = read_csv("quick_sortA.csv")

# Plot all
plt.plot(xW, yW, marker='o', label="Worst Case")
plt.plot(xB, yB, marker='s', label="Best Case")
plt.plot(xA, yA, marker='^', label="Average Case")

plt.title("Quick Sort Time Comparison")
plt.xlabel("n value")
plt.ylabel("Time (us)")
plt.legend()
plt.grid(True)

plt.show()
