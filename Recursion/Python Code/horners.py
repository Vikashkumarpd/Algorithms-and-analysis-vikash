import matplotlib.pyplot as plt
import csv 
x=[]
y=[]
with open("horner.csv","r") as file:
    reader=csv.reader(file)
    for row in reader:
        x.append(int(row[0]))
        y.append(int(row[1]))
plt.plot(x,y, marker='o')
plt.title("horner_algo Time complexity")
plt.xlabel("n value")
plt.ylabel("Time taken (us)")
plt.grid(True)
plt.show()
    
    
