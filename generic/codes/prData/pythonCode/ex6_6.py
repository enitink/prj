def is_palindrome(word):
    if(len(word) == 0):
        return True
    elif(len(word) == 1):
        return True
    elif(word[0] == word[-1]):
        return is_palindrome(word[1:-1])
    else:
        return False

inputstr = raw_input()

print is_palindrome(inputstr)
