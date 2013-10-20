if __name__ == '__main__':
    n = raw_input()
    l = [[1,2,3],[1,5,9],[1,4,7],[2,5,8,0],[2,4],[2,6],[3,5,7],[3,6,9],[4,5,6],[4,8],[6,8],[7,8,9],[1,0],[4,0],[7,0],[3,0],[6,0],[9,0],[1,6],[1,8],[2,7],[2,9],[3,4],[3,8],[4,9],[6,7]]
    n = int(n)
    while(n):
        data = raw_input()
        data = int(data)
        j = 0
        flag = 1
        if((data % 10) == (data / 10000000)):
            flag = 0
        lc = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
        flag2 = 0
	if(data <= 9999999):
             flag2 = 1
        while(1):
            ld = data % 10
            data = data / 10
            d = data % 10
            if(data == 0):
                break
            if(ld == d):
                continue
            for i in range(0, len(l)):
                if ld in l[i]:
                    if d in l[i]:
                        lc[i] = 1
        count = 0
        if(flag == 0):
            for i in range(0, len(l)):
                if ld in l[i]:
                    if(lc[i] == 1):
                        count = count + 1
            if(count > 1):
                print 0
            else:
                print sum(lc)
        else:
            if(flag2 == 1):
                for i in range(0, len(l)):
                    if ld in l[i]:
                        if 0 in l[i]:
                           lc[i] = 1
                print sum(lc)
            else:
                print sum(lc)
        n = n - 1
