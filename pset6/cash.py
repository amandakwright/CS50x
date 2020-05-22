from cs50 import get_float
from decimal import Decimal


def main():
    change = Decimal(get_positive_float())
    coins = 0
    cents = round(change * 100, 2)
    while cents > 0:
        if cents >= 25:
            coins += 1
            cents = cents - 25
        elif cents >= 10:
            coins += 1
            cents = cents - 10
        elif cents >= 5:
            coins += 1
            cents = cents - 5
        else:
            coins += 1
            cents = cents - 1
    print(coins)


def get_positive_float():
    while True:
        n = get_float("Change owed: ")
        if n > 0:
            break
    return n


main()
