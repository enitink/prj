"""
Exercise 10.4 Two words are anagrams if you can rearrange the letters from one to spell the other.
Write a function called is_anagram that takes two strings and returns True if they are anagrams.
"""

def is_anagram(str1, str2):
    lstr1 = []
    lstr2 = []
    for c in str1:
        lstr1.append(c)
    for c in str2:
        lstr2.append(c)
    lstr1.sort()
    lstr2.sort()
    if len(lstr1) != len(lstr2):
        return False
    else:
        for i in range(len(lstr1)):
            if not (lstr1[i] == lstr2[i]):
                return False
    return True

Twords = 0
Pwords = 0
fin = open('words.txt')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    fin1 = open('words.txt')
    for line1 in fin1:
        word1 = line1.strip()
        if not(word == word1):
            if is_anagram(word, word1):
                print word, ' # ', word1
                Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
