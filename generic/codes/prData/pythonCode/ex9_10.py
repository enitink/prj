def is_palindrome(word):
    i = 0
    j = len(word)-1
    while i<j:
        if word[i] != word[j]:
            return False
        i = i+1
        j = j-1
    return True

number = 322223
if is_palindrome(str(number)):
    print 'Required No : ', str(number)
    if is_palindrome(str(number - 1)[-5:]):
        print 'Required No : ', str(number - 1)
        if is_palindrome(str(number - 2)[-4:]):
            print 'Required No : ', str(number - 2)
"""
number = 100002
for i in range(899997):
    if is_palindrome(str(number)):
        if is_palindrome(str(number - 1)[-5:]):
            if is_palindrome(str(number - 2)[-4:]):
                print 'Required No : ', str(number - 2)
    number = number + 1

print number
"""
