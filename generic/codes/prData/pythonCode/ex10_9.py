"""
Exercise 10.9 Two words are a reverse pair if each is the reverse of the other. Write a program
that finds all the reverse pairs in the word list.
"""

def bisect(tlist, searchitem, sindex, lindex):
    if tlist[(sindex + lindex)/2] == searchitem:
        return True
    elif abs(sindex - lindex) <= 1:
        return False
    else:
        if(searchitem > tlist[(sindex + lindex)/2]):
            return bisect(tlist, searchitem, (sindex + lindex)/2, lindex)
        else:
            return bisect(tlist, searchitem, sindex, (sindex + lindex)/2)

#following function uses the bisect function above which is binary search module in python and is faster then using in keyword

def is_rev_pair(word, tlist):
    if word == word[::-1]:
        return False
    if bisect(tlist, word[::-1], 0, len(tlist)):
        return True
    else:
        return False

def is_rev_pair_using_in(word, tlist):
    if word[::-1] in tlist:
        return True
    else:
        return False


fin = open('words.txt')
tlist = []
for line in fin:
    word = line.strip()
    tlist.append(word)

Twords = 0
Pwords = 0
fin = open('words.txt')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    if is_rev_pair(word, tlist):
        print word, ' # ' , word[::-1]
        Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
