def lcm(a,b):
    if(b == 0):
        return a
    else:
        return lcm(b, a%b)

C = raw_input()
C = int(C)
for i in range(C):
    line = raw_input()
    data = []
    data = line.split()
    print "----"
    lcm_all = int(data[1])
    for k in range(2,len(data)):
        lcm_all = lcm(lcm_all, int(data[k]))
    print lcm_all
