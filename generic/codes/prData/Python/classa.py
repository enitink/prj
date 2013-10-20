class Time:
    hour = 0
    minute = 0
    second = 0
    def check(self):
        print 'checking dude'

time = Time()
print time.hour
print time.minute
print time.second
time.hour = 11
time.minute = 59
time.second = 30
"""
t = Time()
print t
t.hour = 12
print t
"""
print time.hour
print time.minute
print time.second
time.check()
