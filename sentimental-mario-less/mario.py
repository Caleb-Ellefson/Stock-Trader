from cs50 import get_int

# Get_int for int between 1 and 8

while True:
    h = get_int ("Height: ")
    if n >= 1 and n <=8:
        break

for i in range(h):
    for j in range(h):
        if i + j >= h - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()



