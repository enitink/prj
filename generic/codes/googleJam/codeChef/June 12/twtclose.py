if __name__ == '__main__':
    word = raw_input()
    word = word.strip()
    word = word.replace('\n','')
    n, k = word.split()
    n = int(n)
    k = int(k)
    twtArr = zeros(1000, Int)
    count = 0
    for i in range(0, n):
        d = raw_input()
	d = int(d)
        if(d % k == 0):
            count += 1
    print count
