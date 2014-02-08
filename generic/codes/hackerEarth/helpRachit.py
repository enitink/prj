import math
def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True

if __name__ == '__main__':
    T = raw_input()
    T = int(T)
    while(T):
       n = raw_input()
       n = int(n)
       c = 0
       cnt1 = n / 2
       s = 0
       gn = 1
       for i in range(cnt1):
           s = s + 2
           for j in range(4):
              gn = gn + s
              if isPrime(gn):
                  c = c + 1
       res = round(100.0 * c / (n + n - 1),6)
       print  res
       T -= 1
