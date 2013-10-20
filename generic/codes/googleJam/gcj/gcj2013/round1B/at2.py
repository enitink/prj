if __name__ == '__main__':
    T = raw_input()
    T = int(T)
    caseN = 1
    while(T):
       n = raw_input()
       a, b = n.split()
       a = int(a)
       b = int(b)
       c = 0
       for i in arr:
           if ((i >= a) and (i <= b)):
               c += 1
       print 'Case #' + str(caseN) + ':' + str(c)
       caseN += 1
       T -= 1
