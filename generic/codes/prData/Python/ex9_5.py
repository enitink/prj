"""
               Write a function named uses_all that takes a word and a string of required letters,
and that returns True if the word uses all the required letters at least once. How many words are
there that use all the vowels aeiou? How about aeiouy?

"""

def uses_all(word, letters):
    word = word.lower()
    letters = letters.lower()
    for c in letters:
        if not c in word:
            return False
    return True

Twords = 0
Pwords = 0
fin = open('words.txt')
uses = raw_input('Enter set letters : ')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    if uses_all(word, uses):
        print word
        Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
