"""
Think Python
Exercise 11.9 rotate pairs
Sol by : Nitin Kumar
Date 24 June 2009
Note : is_rotate_pairs checks the required condition for the problem,i.e, it checks if the letters of the first word are rotated results in formation of the second word or not.
       find_all_rotate_pairs checks the words.txt file for list of rotated words list pair, this function uses the dictionary facility of python
"""

def is_rotate_pairs(word1, word2):
    if not (len(word1) == len(word2)):
        return False
    for i in range(len(word1)):
        if(word1 == word2):
            return True
        else:
            word1 = word1[1:] + word1[0]
    return False

def find_all_rotate_pairs(word, d):
    val = []
    tword = word
    for i in range(len(word)-1):
        word = word[1:] + word[0]
        if (word in d) and (not (word in res)):
            val.append(word)
            res[tword] = val

d = dict()
fin = open('words.txt')
for line in fin:
    word = line.strip()
    d[word] = 1

res = dict()
fin = open('words.txt')
for line in fin:
    word = line.strip()
    find_all_rotate_pairs(word, d)

for line in res:
    print line, ' # ', res[line]
print 'Total no. of results printed : ' , len(res)
