"""
Think Python
Exercise 12.1  
Sol by : Nitin Kumar
Date 24 June 2009
Note : Write a function called sumall that takes any number of arguments and returns their sum
"""

def sumall(*args):
    result = 0
    for n in args:
        result += int(n)
    return result

print sumall(1, 2, 3, 4, 5, 6, 7, 8, 9 , 10)
print sumall(1, 2, 3, 4, 5, 6, 7, 8, 9 , '10')
