from math import *

if __name__ == '__main__':
    T = 1 
    T = int(T)
    while(T):
       n = '1 10'
       a, b = n.split()
       a = int(a)
       b = pow(int(b), 50)
       while(a <= b):
            if(str(a) == str(a)[::-1]):
                if(str(a * a) == str(a*a)[::-1]):
			print '[' + str(a*a) + ']' + ','
            a += 1
       T -= 1 
