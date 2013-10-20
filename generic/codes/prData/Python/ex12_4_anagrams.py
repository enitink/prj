"""
Think Python
Exercise 12.4
Sol by : Nitin Kumar
Date 24 June 2009
Note : More anagram
"""

#part1 of the problem 12.4 starts here
def filter_all(word):
    l = []
    for c in word:
        l.append(c)
    l.sort()
    tword = ''.join(l)
    d[tword] = d.get(tword, []) + [word]
#part1 of the problem 12.4 ends here

#part1 being used here
d = dict()
fin = open('words.txt')

for line in fin:
    word = line.strip()
    filter_all(word)

di = dict()

for line in d:
    if len(d[line]) >= 2:
        di[line] = d[line]

#for line in di:
 #   print di[line]

#part1 used

#part2 of the problem 12.4 starts here

def most_common(h):
    t = []
    for key, value in h.items():
        t.append((len(value), value))
    t.sort(reverse=True)
    return t

tlist = most_common(di)
for t in tlist:
    print t
#part2 of the problem 12.4 ends here
