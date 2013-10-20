from TurtleWorld import *
import math

def Arc(t, radius, deg):
    t.delay = 0.01
    circumference = 2 * math.pi * radius
    n = circumference / 2
    d = 360 / n
    temp = 360 / deg
    n = int(n / temp)
    print n
    for i in range(n):
        fd(t, n)
        lt(t, d)

def arc(t, r, angle):
    arc_length = 2 * math.pi * r * angle / 360
    n = int(arc_length / 3) + 1
    step_length = arc_length / n
    step_angle = float(angle) / n
    for i in range(n):
        fd(t, step_length)
        lt(t, step_angle)

world = TurtleWorld()
t = Turtle()
arc(t, 100, 90)
die(t)
wait_for_user()
