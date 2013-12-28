def ack(m, n):
    if(m==0):
        return n + 1
    elif((m > 0) and (n == 0)):
        return ack(m - 1, 1)
    elif(m > 0 and n > 0):
        return ack(m - 1, ack(m, n - 1))


print ack(1,1)
print ack(1,2)
print ack(1,3)
print ack(1,4)
print ack(1,5)
print ack(1,6)
print ack(1,7)
print ack(1,8)
print ack(1,9)
print ack(1,10)
print ack(1,11)
print ack(1,12)
