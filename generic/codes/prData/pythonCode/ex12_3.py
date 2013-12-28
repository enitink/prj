"""
Think Python
Exercise 12.3  
Sol by : Nitin Kumar
Date 24 June 2009
Note : Write a function called most_frequent that takes a string and prints the letters in decreasing order of frequency.
"""

def most_frequent(string):
    for c in string:
        d[c] = d.get(c, 0) + 1

d = dict()

fin = open('words.txt')
for line in fin:
    string = line.strip()
    most_frequent(string)

for i in d:
    print i ,' # ', d[i]
