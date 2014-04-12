def pascal(n):
   """Prints out n rows of Pascal's triangle.
   It returns False for failure and True for success."""
   row = [1]
   k = [0]
   for x in range(max(n,0)):
      print row
      row=[(l+r)%1000000007 for l,r in zip(row+k,k+row)]
   return n>=1

if __name__ == '__main__':
    T = raw_input()
    T = int(T)
    pascal(T)
