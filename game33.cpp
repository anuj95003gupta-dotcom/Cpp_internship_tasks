#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char board[3][3]; // 3x3 board

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the current board state
void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if the game is over (win or draw)
bool isGameOver() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] != ' ') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return true; // row win
        }
        if ((board[0][i] != ' ') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return true; // column win
        }
    }
    if ((board[0][0] != ' ') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return true; // diagonal win
    }
    if ((board[0][2] != ' ') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        return true; // diagonal win
    }

    // Check for a draw (all cells filled)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // game is not over yet
            }
        }
    }
    return true; // it's a draw
}

// Function to check if the move is valid
bool isValidMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false; // out of bounds
    }
    if (board[row][col] != ' ') {
        return false; // cell already occupied
    }
    return true;
}

// Function to make a move
void makeMove(int row, int col, char currentPlayer) {
    board[row][col] = currentPlayer;
}

// Function for AI to make a move (simple random move)
void makeAIMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (!isValidMove(row, col));

    makeMove(row, col, 'O');
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    initializeBoard();
    bool isPlayerX = true;
    bool gameOver = false;

    while (!gameOver) {
        if (isPlayerX) {
            displayBoard();
            int row, col;
            cout << "Player X, enter your move (row and column): ";
            cin >> row >> col;

            if (isValidMove(row, col)) {
                makeMove(row, col, 'X');
                gameOver = isGameOver();
                if (gameOver) {
                    displayBoard();
                    cout << "Player X wins!" << endl;
                } else {
                    isPlayerX = !isPlayerX;
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        } else {
            makeAIMove();
            displayBoard();
            gameOver = isGameOver();
            if (gameOver) {
                cout << "AI wins!" << endl;
            } else {
                isPlayerX = !isPlayerX;
            }
        }
    }

    if (!gameOver) {
        displayBoard();
        cout << "It's a draw!" << endl;
    }

    return 0;
}
