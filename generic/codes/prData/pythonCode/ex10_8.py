def bisect(tlist, searchitem, sindex, lindex):
    if tlist[(sindex + lindex)/2] == searchitem:
        return True
    elif abs(sindex - lindex) <= 1:
        return False
    else:
        if(searchitem > tlist[(sindex + lindex)/2]):
            return bisect(tlist, searchitem, (sindex + lindex)/2, lindex)
        else:
            return bisect(tlist, searchitem, sindex, (sindex + lindex)/2)

fin = open('words.txt')
tlist = []
for line in fin:
    word = line.strip()
    tlist.append(word)

print bisect(tlist, 'english', 0, len(tlist))
print bisect(tlist, 'notably', 0, len(tlist))
print bisect(tlist, 'zymurgy', 0, len(tlist))
print bisect(tlist, 'alto', 0, len(tlist))
print bisect(tlist, 'eglish', 0, len(tlist))
print bisect(tlist, 'ntably', 0, len(tlist))
print bisect(tlist, 'zmurgy', 0, len(tlist))
print bisect(tlist, 'ato', 0, len(tlist))

