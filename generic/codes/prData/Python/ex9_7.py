def is_tcons(word):
    lword = ''
    rletter = False
    result = ''
    for c in word:
        if lword == c and (not rletter):
            rletter = True
            result = result + 'T'
        else:
            lword = c
            rletter = False
            result = result + 'F'
    if 'TFTFT' in result:
        return True
    else:
        return False
          

Twords = 0
Pwords = 0
fin = open('words.txt')
for line in fin:
    word = line.strip()
    Twords = Twords + 1
    if is_tcons(word):
        print word
        Pwords = Pwords + 1

Twords = Twords * 1.0
per = (Pwords/Twords) * 100
print "Total Words = " , str(Twords)
print "Printed Words = " , str(Pwords)
print "Percentage = " , str(per)
