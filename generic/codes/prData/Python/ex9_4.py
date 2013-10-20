"""
              Write a function named uses_only that takes a word and a string of letters, and that
returns True if the word contains only letters in the list. Can you make a sentence using only the
letters acefhlo? Other than 'Hoe alfalfa?'

"""
def uses_only(word, letters):
    word = word.lower()
    letters = ' ' + letters.lower()
    for c in word:
        if not c in letters:
            return False
    return True

#print uses_only('Hoeal falfac','acefhlo')

Twords = 0
Pwords = 0
fin = open('words.txt')
uses = raw_input('Enter set letters : ')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    if uses_only(word, uses):
        print word
        Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
