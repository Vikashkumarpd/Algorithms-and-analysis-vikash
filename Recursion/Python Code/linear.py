# import matplotlib.pyplot as plt
# import csv


# with open("linerA.csv", "r") as file:
#     reader = csv.reader(file)
#     for row in reader:
#         x.append(int(row[0]))
#         y.append(int(row[1]))

# x1, y1 = read_csv("linearA.csv")
# x2, y2 = read_csv("knaprt.csv")
# x3, y3 = read_csv("knapwt.csv")

# plt.plot(x1, y1, marker='o', label="Taking maximum profit first")
# plt.plot(x2, y2, marker='s', label="Maximum profit by ratio")
# plt.plot(x3, y3, marker='^', label="Taking weight for maximum profit")


# plt.title("liner_search")
# plt.xlabel("n value")
# plt.ylabel("Time (ns)")
# plt.grid(True)
# plt.show()

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



x1, y1 = read_csv("csv_file/avg.csv")
x2, y2 = read_csv("csv_file/worst.csv")
x3, y3 = read_csv("csv_file/best.csv")



plt.plot(x1, y1, marker='o', label="Average case")
plt.plot(x2, y2, marker='s', label="Worst case")
plt.plot(x3, y3, marker='^', label="Best case")



plt.title("Linear search")
plt.xlabel("Size of array")
plt.ylabel("Time")
plt.grid(True)

plt.legend()   

plt.show()
