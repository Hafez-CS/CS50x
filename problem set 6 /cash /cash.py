from cs50 import get_float


def get_cents():
    a = get_float("Change owed:")
    while a < 0:
        a = get_float("Change owed:")
    a = a * 100
    return a


def calculate_quarters(cents):
    b = cents / 25
    return b


def calculate_dimes(cents):
    c = cents / 10
    return c


def calculate_nickels(cents):
    d = cents / 5
    return d


def calculate_pennies(cents):
    e = cents / 1
    return e

    # Ask how many cents the customer is owed


cents = int(get_cents())

# Calculate the number of quarters to give the customer
quarters = int(calculate_quarters(cents))
cents = cents - quarters * 25

# Calculate the number of dimes to give the customer
dimes = int(calculate_dimes(cents))
cents = cents - dimes * 10

# Calculate the number of nickels to give the customer
nickels = int(calculate_nickels(cents))
cents = cents - nickels * 5

# Calculate the number of pennies to give the customer
pennies = int(calculate_pennies(cents))
cents = cents - pennies * 1

# Sum coins
coins = int(quarters + dimes + nickels + pennies)

# Print total number of coins to give the customer
print(coins)
