"""
Problem Statement: To find the factorial of nos.. the nos may be from 0 < n < 100.. that's y...
I used python... in C such a long digit... you have to handle by urself!!
"""
if __name__ == '__main__':
    n = raw_input()
    for i in range(0,int(n)):
        d = raw_input()
	d = int(d)
        fact = 1
        while(d > 1):
            fact *= d
            d = d - 1
        print fact
