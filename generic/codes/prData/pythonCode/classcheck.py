class a:
    def amethod(self):
        print 'i m in method a'

class b(a):
    def bmethod(self):
        print 'i m in method b'

class c(a):
    def cmethod(self):
        print 'i m in method c'

class d(b):
    def dmethod(self):
        print 'i m in method d'

def find_defining_class(obj, meth_name):
    for ty in type(obj).mro():
        print 'ty.dict #' , str(ty.__dict__)
        if meth_name in ty.__dict__:
            return ty

obja = a()
objb = b()
objc = c()
objd = d()

obja.amethod()
objb.amethod()
objc.amethod()
objd.amethod()

print find_defining_class(objd, 'amethod')
