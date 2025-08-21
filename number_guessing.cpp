#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
    int playerGuess;
    int attempts = 7;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "You have " << attempts << " attempts to guess the number between 1 and 100." << endl;

    for (int i = 0; i < attempts; ++i) {
        cout << "Attempt " << (i + 1) << ": Enter your guess: ";
        cin >> playerGuess;

        if (playerGuess < 1 || playerGuess > 100) {
            cout << "Please guess a number between 1 and 100." << endl;
            --i; // Do not count this attempt
            continue;
        }

        if (playerGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else if (playerGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the number: " << numberToGuess << endl;
            break; // Exit the loop if the guess is correct
        }

        if (i == attempts - 1) {
            cout << "Sorry, you've used all your attempts. The number was: " << numberToGuess << endl;
        }
    }

    return 0;
}
