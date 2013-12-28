"""
Think Python
Exercise 9.2  
Sol by : Nitin Kumar
Date 14 June 2009
Note : In 1939 Ernest Vincent Wright published a 50,000 word novel called Gadsby that does
not contain the letter “e.” Since “e” is the most common letter in English, that’s not easy to do.
In fact, it is difficult to construct a solitary thought without using that most common symbol. It is
slow going at first, but with caution and hours of training you can gradually gain facility.
All right, I’ll stop now.
Write a function called has_no_e that returns True if the given word doesn’t have the letter “e” in
it.
Modify your program from the previous section to print only the words that have no “e” and compute
the percentage of the words in the list have no “e.”

"""

def has_no_e(word):
    if 'e' in word:
        return False
    else:
        return True

Twords = 0
Pwords = 0
fin = open('words.txt')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    if has_no_e(word):
        print word
        Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
