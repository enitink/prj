"""
Exercise 10.3 Write a function called is_sorted that takes a list as a parameter and returns True
if the list is sorted in ascending order and False otherwise. You can assume (as a precondition) that
the elements of the list can be compared with the comparison operators <, >, etc.
"""

def is_sorted(tlist):
    for t in range(len(tlist) - 1):
        if tlist[t] > tlist[t + 1]:
           return False
    return True

print is_sorted([1,2,3,4,5,6])
print is_sorted([1,1,2,3,4,5,6,1])
print is_sorted([1,2,1,3,4,5,6])
print is_sorted(['a','b','c','d'])
string = 'my name is nitin kumar'
print is_sorted(sorted(string.split()))
