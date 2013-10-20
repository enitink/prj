"""
code searches for a string subset in a given string... and prints 1 if string is there else 0
"""
if __name__ == '__main__':
    t = raw_input()
    t = int(t.strip())
    while(t):
        word = raw_input()
        word = word.strip()
        word = word.replace('\n','')
        a, b = word.split()
        if(b in a):
             print 1
        else:
             print 0
        t = t - 1
