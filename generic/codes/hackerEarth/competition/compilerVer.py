import string
import sys
if __name__ == '__main__':
    while True:
        T = sys.stdin.readline()
        if T == "":
            break;
        commentIndex = string.find(T,"//")
        T = string.replace(T[0:commentIndex],"->",".") + T[commentIndex:] 
        sys.stdout.write(T)
