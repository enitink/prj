from TurtleWorld import *
import math

def arc(r, angle):
    t = Turtle()
    arc_length = 2 * math.pi * r * angle / 360
    n = int(arc_length / 3) + 1
    for i in range(n):
        fd(t, 1)
        lt(t, 1)

world = TurtleWorld()
arc(60, 90)
wait_for_user()
