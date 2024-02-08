from cs50 import get_int

# get the Height
while True:
    height = get_int("Height:")
    if height <= 8 and height >= 1:
        break

# Making a loop for the height
for i in range(height):
    # calculating the space     # height - 1 is because the start of i is 0
    space = (height - 1) - i

    # printing  the spaces
    for j in range(space):
        print(" ", end="")

    for n in range(i + 1):
        print("#", end="")

    # printing the 2 space
    print("  ", end="")

    for n in range(i + 1):
        print("#", end="")

    print("")
