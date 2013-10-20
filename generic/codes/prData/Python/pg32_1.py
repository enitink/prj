from TurtleWorld import *

def Square(t, length):
    for i in range(4):
        fd(t, length)
        lt(t)

world = TurtleWorld()
t = Turtle()
Square(t, 20)
wait_for_user()
