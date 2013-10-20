from math import *

if __name__ == '__main__':
    T = raw_input()
    T = int(T)
    while(T):
       n = raw_input()
       a, b = n.split()
       a = int(a)
       b = int(b)
       while(a <= b):
            if(str(a) == str(a)[::-1]):
                if(str(a * a) == str(a*a)[::-1]):
			print '[' + str(a*a) + ']' + ','
            a += 1
       print
       T -= 1 
