# -*- coding: utf-8 -*-
"""
Created on Sun Jul  2 20:41:14 2023

@author: caden
"""
import matplotlib.pyplot as plt
import csv

t = []
av1 = []
a1 = []
x1 = []
y1 = []
av2 = []
a2 = []
x2 = []
y2 = []

# open the file
with open('graph.csv' , 'r') as csvfile:
    # create the object of csv.reader()
    csv_file_reader = csv.reader(csvfile,delimiter=',')
    for row in csv_file_reader:
        t.append(float(row[0]))
        av1.append(float(row[1]))
        av2.append(float(row[2]))
        a1.append(float(row[3]))
        a2.append(float(row[4]))
        x1.append(float(row[5]))
        y1.append(float(row[6]))
        x2.append(float(row[7]))
        y2.append(float(row[8]))

fig, ax = plt.subplots()
ax.grid(True, which='both')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.yaxis.tick_left()
ax.spines['bottom'].set_position('zero')
ax.spines['top'].set_color('none')
ax.xaxis.tick_bottom()

#ax.plot(t,av1)
#ax.plot(t,av2)
#ax.plot(t,a1)
#ax.plot(t,a2)
#ax.plot(t,x1)
#ax.plot(t,y1)
#ax.plot(t,x2)
#ax.plot(t,y2)
ax.plot(x1,y1)
ax.plot(x2,y2)

ax.xaxis.set_label_position('bottom')
ax.set_xlabel("Time")
ax.set_ylabel("Magnitude")