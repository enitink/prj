from TurtleWorld import *

def Polygon(sides):
    t = Turtle()
    t.delay = 0.01
    deg = 360 / sides
    length = 360 / sides
    for i in range(sides):
        fd(t, length)
        lt(t, deg)

world = TurtleWorld()
Polygon(10)
wait_for_user()
