"""
This program is just to find the no. of inputed no divisible by a given no. the no of inputed nos in very large.. so fast calculation is needed..
and cpp was performing very slow.. though with the same logic...
"""
if __name__ == '__main__':
    word = raw_input()
    word = word.strip()
    word = word.replace('\n','')
    n, k = word.split()
    n = int(n)
    k = int(k)
    count = 0
    for i in range(0, n):
        d = raw_input()
	d = int(d)
        if(d % k == 0):
            count += 1
    print count
