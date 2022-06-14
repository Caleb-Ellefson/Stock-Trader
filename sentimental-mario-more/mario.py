from cs50 import get_int

while True:
    h = get_int ("Height: ")
    if h >= 1 and h <=8:
        break

for i in range(n):
    print(" " * (n - 1 - i), end="")
    print("#" * (i + 1), end="")
    print(" " * 2, end="")
    print()
