"""
              Write a function called is_abecedarian that returns True if the letters in a word
appear in alphabetical order (double letters are ok). How many abecedarian words are there?
"""

def is_abecedarian(word):
    word = word.lower()
    i = 1
    l = len(word)
    for c in word:
        if (not c <= word[i:]) and (i < l):
            return False
        i = i + 1
    return True

Twords = 0
Pwords = 0
fin = open('words.txt')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    if is_abecedarian(word):
        print word
        Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
