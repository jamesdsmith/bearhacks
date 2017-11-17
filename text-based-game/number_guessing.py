# This is a short text-based game meant to serve as an example for BearHacks
import random

# Note that this function does not do anything until it is called
def compare_function(user_guess, true_val):
    '''This function will compare the a user's value to the true value.
    If the values are equal, the function will print out correct and return True
    else, the function will print out whether the guess was too high or too  low
    and return False'''
    if (user_guess<true_val):
        print("Your guess of ", user_guess, "is too low!")
    elif (user_guess>true_val):
        print("Your guess of ", user_guess, "is too high!")
    else:
        print(str(user_guess) + " is correct!")

    return (user_guess==true_val)

# This section will actually run our code.

print("Welcome to a Number-Guessing Game!!")

# int(x) will try to convert x into an integer
upper_bound = int(input("Please enter an upper-bound for the numbers you want to guess: "))

# Small sanity check
while (upper_bound < 0):
    print("Invalid Bound")
    upper_bound = input("Please enter an upper-bound for the numbers you want to guess: ")

# random.random() will return a random decimal between 0 and 1
true_val = round(random.random()*upper_bound)

is_correct = False
num_guesses = 0
while (not is_correct):
    num_guesses += 1 # equivalent to num_guesses = num_guesses + 1
    guess = int(input("Guess a number! "))
    is_correct = compare_function(guess, true_val)

print("Congratulations! It took you ", num_guesses, " tries.")
