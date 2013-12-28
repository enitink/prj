def print_spam(str1, arg):
    print str1 + ' : ' + str(arg)

def do_twice(f,x,y):
    f('string 1 here',x)
    f('string 2 here',y)

do_twice(print_spam,1,2)


#this examples last part is not complete, for it vist thinkpython.com/code/do_four.py
