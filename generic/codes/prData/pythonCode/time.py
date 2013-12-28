class time:
    def __init__(self, hour=0, minute=0, second=0):
        self.hour = hour
        self.minute = minute
        self.second = second
    def __str__(self):
        return '%.2d:%.2d:%.2d:%d' % (self.hour, self.minute, self.second, self.newattr)
    def add_attr(self):
        self.newattr = 1

t = time()
print t.hour
t.hour = 1
print t.hour
t.add_attr()
print t
