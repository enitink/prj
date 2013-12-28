def print_f(rc):
    print '+',
    for i in range(rc):
        print ' -'*4,
        print '+',
    print ''

def print_first(rc):
    for j in range(rc):
        print_f(rc)
        print_Sec(rc)
    print_f(rc)

def print_Sec(rc):
    for j in range(4):
        for i in range(rc + 1):
            print '|', 
            print '  ' * 4,
        print ''

print_first(2)

print_first(3)

print_first(4)

