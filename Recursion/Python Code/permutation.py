import matplotlib.pyplot as plt
import csv

x = []
y = []

with open("permutation.csv", "r") as file:
    reader = csv.reader(file)
    for row in reader:
        x.append(int(row[0]))
        y.append(int(row[1]))

plt.plot(x, y, marker='o')
plt.title("permutation generator complexity")
plt.xlabel("length of string")
plt.ylabel("Time (ns)")
plt.grid(True)
plt.show()
