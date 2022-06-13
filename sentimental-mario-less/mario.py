from cs50 import get_int

# Get_int for int between 1 and 8
h = get_int ("Height: ")

if (h < 1 and h > 8):

    print("Invaild Height")


for i in range(h):
    print("#")


