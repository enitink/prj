def ans(n, k):
    if((n - k) > k):
        j = k
        for i in range(n, n - k):
            a *= i
            t *= j
            j -= 1
            if(0 == a % t):
                a /= t
                t = 1
    else:
        j = n - k
        for i in range(n, k):
            a *= i
            t *= j
            j -= 1
            if(0 == a % t):
                a /= t
                t = 1
    return a
            
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
        if((a == 0) or (b == 0)):
            print "0"
        else:
            print ans(a, b)
        T -= 1
        if(T):
            print
