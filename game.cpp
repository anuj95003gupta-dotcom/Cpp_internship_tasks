#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(NULL)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int tries = 0;
    bool guessed = false;

    cout << "Welcome to Guess the Number Game!" << endl;
    cout << "Try to guess the number between 1 and 100." << endl;

    while (!guessed) {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess == secretNumber) {
            cout << "Congratulations! You've guessed the number in " << tries << " tries." << endl;
            guessed = true;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }

    return 0;
}

