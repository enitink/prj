def gcd(a, b):
    if(b == 0):
        return a
    else:
        return gcd(b, a%b)

if __name__ == '__main__':
    t = raw_input()
    ti = int(t)
    while(ti):
        n = raw_input()
        ni = int(n)
        l = [[0,0]]
        i = 1
        last = 1
        while(ni):
            a = raw_input()
            a,b = a.split('/')
            c = int(a)
            d = int(b)
            if(i == 1):
                l.append([c,d])
            else:
                if((l[i - 1][0]/l[i - 1][1]) <= ((l[i - 1][0] + c)/(l[i - 1][1]+ d))):
                    c += l[i - 1][0]
                    d += l[i - 1][1]
                    l.append([c,d])
                else:
                    l.append([c,d])
                    for j in range(last - 1, i - 1):
                        c = l[i - 1][0] - l[j][0]
                        d = l[i - 1][1] - l[j][1]
                        gc = gcd(c,d)
                        c /= gc
                        d /= gc
                        print str(c)+'/'+str(d)
                    l[i - 1][0] = 0
                    l[i - 1][1] = 0
                    last = i
            ni = ni - 1
            i = i + 1
        for j in range(last - 1, i - 1):
            c = l[i - 1][0] - l[j][0]
            d = l[i - 1][1] - l[j][1]
            gc = gcd(c,d)
            c /= gc
            d /= gc
            print str(c)+'/'+str(d)
        print ""
        ti = ti - 1
        if(ti):
            raw_input()
