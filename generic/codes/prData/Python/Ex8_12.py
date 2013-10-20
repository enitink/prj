def rotate_word(string, shiftno):
    i = 0
    for c in string:
        if c.islower():
            string = string[0:i] + chr((ord(c) + shiftno - 97) % 26 + 97) + string[i+1:0]
        else:
            string = string[0:i] + chr((ord(c) + shiftno - 65) % 26 + 65) + string[i+1:0]
        i = i + 1
    return string

print rotate_word('Cheer', 7)
print rotate_word(rotate_word('Cheer', 7), -7)
print rotate_word('melon', -10)
print rotate_word(rotate_word('melon', -10), 10)
