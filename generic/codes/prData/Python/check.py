def histogram(s):
    d = dict()
    for c in s:
        if c not in d:
             d[c] = 1
        else:
             d[c] += 1
    return d

def invert_dict(d):
    inv = dict()
    for key in d:
        val = d[key]
        if val not in inv:
            inv[val] = [key]
        else:
            inv[val].append(key)
    return inv

def check(*args):
    for n in args:
        print ''
        print n,
        if type(n) == type(1):
            print '# int',
        elif type(n) == type('string'):
            print '# string',
        elif type(n) == type([]):
            print '# list',

#this portion checks histogram and invert_dict fucntion
hist = histogram('parrot')
print hist
inv = invert_dict(hist)
print inv


#this portion checks check funtion
check(1,2,'ab','190', ['a','b'])
