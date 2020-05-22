from cs50 import get_int


def main():
    h = get_positive_int()
    for i in range(h):
        for j in range(h-i-1):
            print(" ", end="")
        for k in range(i+1):
            print("#", end="")
        print()


def get_positive_int():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n


main()
