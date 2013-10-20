"""
Given n, calculate the sum LCM(1,n) + LCM(2,n) + .. + LCM(n,n), where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
"""
from math import *

def GCD(a, b):
    if( b == 0):
        return a;
    else:
        return GCD(b, a%b)

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
       n = int(n)
       lcmsum = 0
       tsum = 2
       if(IsPrime(n)):
            lcmsum = ((n * (n - 1) / 2) + 1)* n
       else:
            for i in range(2, n):
                if((n % i) == 0):
                    tsum += 1
                else:
                    tsum += (i / GCD(i,n))
            lcmsum = tsum * n
       print lcmsum      
       T -= 1 
