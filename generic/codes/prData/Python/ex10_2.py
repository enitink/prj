"""
Exercise 10.2 Write a function called chop that takes a list and modifies it, removing the first and
last elements, and returns None.
Then write a function called middle that takes a list and returns a new list that contains all but the
first and last elements.
"""

def chop(tlist):
    del tlist[0]
    del tlist[-1]

def middle(tlist):
    t = tlist[0:]
    chop(t)
    return t

t = ['1','2','3','4','5']
print t
chop(t)
print t
t = ['1','2','3','4','5']
print t
print middle(t)
print t

