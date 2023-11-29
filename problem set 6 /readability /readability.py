from cs50 import get_float
from cs50 import get_int
from cs50 import get_string


# forletters
def letters(word):
    a = len(word)
    b = 0
    n = 0
    p = 0

    for i in range(a):
        g = ord(word[i])
        if g >= 65 and g <= 90 or g >= 97 and g <= 122:
            b += 1

    return b


##############################################################################################################


def words(word):
    c = len(word)
    n = 0

    for h in range(c):
        g = ord(word[h])
        if g == 32:
            n += 1
    return n + 1


##############################################################################################################


# for sentences
def sentences(word):
    a = len(word)
    t = 0
    r = 0
    q = 0

    for i in range(a):
        g = ord(word[i])
        if g == 46 or g == 33 or g == 63:
            t += 1

    return t


# @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


# Get input words from both players
word = get_string("Text: ")


# Score both words
x = float(letters(word))
y = float(words(word))
z = float(sentences(word))


r = float((x / y) * 100)
e = float((z / y) * 100)
c = float((0.0588 * r - 0.296 * e - 15.8))


u = int(round(c))


# find out about grades
if u < 1:
    print("Before Grade 1")
elif u > 16:
    print("Grade 16+")
else:
    print("Grade", u)
