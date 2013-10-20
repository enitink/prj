def gcd(a, b):
    if(b == 0):
        return a
    else:
        return gcd(b, a%b)

if __name__ == '__main__':
    t = raw_input()
    t = t.replace('\n','')
    t = int(t)
    while(t):
        n = raw_input()
        n = int(n)
        l = [[0,0]]
        i = 1
        last = 1
        while(n):
            a = raw_input()
            a,b = a.split('/')
            a = int(a)
            b = int(b)
            if(i == 1):
                l.append([a,b])
            else:
                if((l[i - 1][0]/l[i - 1][1]) <= ((l[i - 1][0] + a)/(l[i - 1][1]+b))):
                    a += l[i - 1][0]
                    b += l[i - 1][1]
                    l.append([a,b])
                else:
                    l.append([a,b])
                    for j in range(last - 1, i - 1):
                        a = l[i - 1][0] - l[j][0]
                        b = l[i - 1][1] - l[j][1]
                        gc = gcd(a,b)
                        a /= gc
                        b /= gc
                        print str(a)+'/'+str(b)
                    l[i - 1][0] = 0
                    l[i - 1][1] = 0
                    last = i
            n = n - 1
            i = i + 1
        for j in range(last - 1, i - 1):
            a = l[i - 1][0] - l[j][0]
            b = l[i - 1][1] - l[j][1]
            gc = gcd(a,b)
            a /= gc
            b /= gc
            print str(a)+'/'+str(b)
        print ""
        t = t - 1
        if(t):
            raw_input()
