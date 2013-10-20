from TurtleWorld import *
import math
import poly

"""def Circle(t, radius):
    t.delay = 0.01
    circumference = 2 * math.pi * radius
    n = int(circumference)
    d = 360 / n
    for i in range(n):
        fd(t, n)
        lt(t, d)
"""

def Circle(radius):
    Polygon(2 * math.pi * radius)

world = TurtleWorld()
Circle(6)
wait_for_user()
