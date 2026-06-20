#include<iostream>
#include<cstdlib>
#include<ctime>

#define ROCK 1 //Preprocessor constant which helps to generate rock,paper,scissors from AI side
#define PAPER 2
#define SCISSORS 3
using namespace std;

int main() {
    srand((unsigned int)time(NULL));//Used to generate a random number everytime the game is played.
    int player_throw = 0;
    int com_throw = 0;
    bool draw = false;

    do {
        cout << "Select your choice:" << endl;
        cout << "1)Rock." << endl;
        cout << "2)Paper." << endl;
        cout << "3)Scissors." << endl;
        cout << "You selected:";
        cin >> player_throw;

        cout << endl;

        com_throw = (rand() % 3) + 1; //This is used for AI to select ROCK,PAPER,SCISSORS.
        
		if (com_throw == ROCK) {
            cout << "COM throws Rock"<<endl;
        } else if (com_throw == PAPER) {
            cout << "COM throws Paper"<<endl;
        } else if (com_throw == SCISSORS) {
            cout << "COM throws Scissors"<<endl;
        }
        draw = false;

        if (player_throw == com_throw) {
        	draw=true;
            cout << "It's a draw! Play Again!"<<endl;
        } else if (player_throw == PAPER && com_throw == ROCK) {
            cout << "PAPER beats ROCK! You win!"<<endl;
        } else if (player_throw == ROCK && com_throw == PAPER) {
            cout << "PAPER beats ROCK! You lose!"<<endl;
        } else if (player_throw == SCISSORS && com_throw == PAPER) {
            cout << "SCISSORS beats PAPER! You win!"<<endl;
        } else if (player_throw == PAPER && com_throw == SCISSORS) {
            cout << "SCISSORS beats PAPER! You lose!"<<endl;
        } else if (player_throw == ROCK && com_throw == SCISSORS) {
            cout << "ROCK beats SCISSORS! You win!"<<endl;
        } else if (player_throw == SCISSORS && com_throw == ROCK) {
            cout << "ROCK beats SCISSORS! You lose!"<<endl;
        }

        cout << endl;

    } while (draw);
    
    return 0;
}

