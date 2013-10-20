"""
Given n, calculate the sum LCM(1,n) + LCM(2,n) + .. + LCM(n,n), where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
"""
from math import *

def IsPrime(a):
    for i in range(2, int(sqrt(a)) + 1):
        if((a % i) == 0):
            return False
    return True

if __name__ == '__main__':
    T = raw_input()
    T = int(T)
    while(T):
       n = raw_input()
       n = n.strip()
       n = n.replace('\n','')
       a, b = n.split()
       a = int(a)
       b = int(b)
       while(a <= b):
            if(IsPrime(a)):
                print a
            a += 1
       print
       T -= 1 
