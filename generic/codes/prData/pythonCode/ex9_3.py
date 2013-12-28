"""
               Write a function named avoids that takes a word and a string of forbidden letters, and
that returns True if the word doesn’t use any of the forbidden letters.
Modify your program to prompt the user to enter a string of forbidden letters and then print the
number of words that don’t contain any of them. Can you find a combination of 5 forbidden letters
that excludes the smallest number of words?

"""

def avoids(word, forb):
    for c in forb:
        if c in word:
            return False
    return True

Twords = 0
Pwords = 0
fin = open('words.txt')
forb = raw_input('Enter forbidden letters : ')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    if avoids(word, forb):
        print word
        Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
