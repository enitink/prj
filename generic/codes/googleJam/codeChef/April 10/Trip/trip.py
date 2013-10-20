if __name__ == '__main__':
    t = raw_input()
    t = t.strip()
    t = t.replace('\n','')
    N, M = t.split()
    N = int(N)
    M = int(M)
    while(N):
        t = raw_input()
        t = int(t)
        N = N - 1
