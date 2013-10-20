t = raw_input()
t = int(t)
for i in range(1, t + 1):
    line = raw_input()
    a, b = line.split()
    a = int(a)
    b = int(b)
    res = 0
    for j in range(a, b + 1):
        jStr = str(j)
        l = len(jStr)
        jStr += jStr
        for k in range(l):
            num = int(jStr[k:l+k])
            if(num >= a and num <= b):
                if(num != j):
                    res += 1
                    print str(num) + " : " + jStr
    print "Case #" + str(i) + ": " + str(res / 2)
