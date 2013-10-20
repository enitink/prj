import random

print 5
for i in range(5):
    print 100000
    for i in range(100000):
        x = random.randint(0, 100000)
        y = random.randint(0, 100000)
        print str(x) + "/" + str(y)
    print ""
