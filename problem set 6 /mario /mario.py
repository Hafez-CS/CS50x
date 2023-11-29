from cs50 import get_int


n = get_int("pleas enter number between 1,8 : ")
# we cant get a number


while n > 8 or n < 1:  # make sure its 1 - 8
    n = get_int("pleas enter number between 1,8 : ")


for i in range(n):
    if i == 0:
        for w in range(n - (i + 1)):
            print(" ", end="")
        for t in range(1):
            print("#", end="")
    else:
        for q in range(n - (i + 1)):
            print(" ", end="")  # make space
        for z in range(i + 1):
            print("#", end="")  # make #
    print()
