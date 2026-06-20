#include <iostream>
#include <vector>

const int ROWS = 6;
const int COLS = 7;

class ConnectFour {
private:
    char board[ROWS][COLS];
    int currentPlayer;

public:
    ConnectFour() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 1;
    }

    void printBoard() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                std::cout << "| " << board[i][j] << " ";
            }
            std::cout << "|\n";
        }
        std::cout << "-----------------------------\n";
    }

    bool dropDisc(int col) {
        for (int i = ROWS - 1; i >= 0; --i) {
            if (board[i][col] == ' ') {
                board[i][col] = (currentPlayer == 1) ? 'X' : 'O';
                return true;
            }
        }
        return false; // Column is full
    }

    bool checkWin() {
        // Check horizontally
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i][j + 2] &&
                    board[i][j] == board[i][j + 3]) {
                    return true;
                }
            }
        }

        // Check vertically
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 2][j] &&
                    board[i][j] == board[i + 3][j]) {
                    return true;
                }
            }
        }

        // Check diagonally (down-right)
        for (int i = 0; i <= ROWS - 4; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i + 1][j + 1] &&
                    board[i][j] == board[i + 2][j + 2] &&
                    board[i][j] == board[i + 3][j + 3]) {
                    return true;
                }
            }
        }

        // Check diagonally (up-right)
        for (int i = 3; i < ROWS; ++i) {
            for (int j = 0; j <= COLS - 4; ++j) {
                if (board[i][j] != ' ' &&
                    board[i][j] == board[i - 1][j + 1] &&
                    board[i][j] == board[i - 2][j + 2] &&
                    board[i][j] == board[i - 3][j + 3]) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    int getCurrentPlayer() {
        return currentPlayer;
    }
};

int main() {
    ConnectFour game;
    int column;

    do {
        game.printBoard();

        // Get the current player's move
        std::cout << "Player " << game.getCurrentPlayer() << ", enter a column (0-6): ";
        std::cin >> column;

        // Drop the disc into the column
        if (column >= 0 && column < COLS) {
            if (!game.dropDisc(column)) {
                std::cout << "Column is full. Try again.\n";
                continue;
            }

            // Check for a win
            if (game.checkWin()) {
                game.printBoard();
                std::cout << "Player " << game.getCurrentPlayer() << " wins!\n";
                break;
            }

            // Check for a tie
            if (game.isBoardFull()) {
                game.printBoard();
                std::cout << "It's a tie!\n";
                break;
            }

            // Switch to the next player
            game.switchPlayer();
        } else {
            std::cout << "Invalid column. Please enter a column between 0 and 6.\n";
        }

    } while (true);

    return 0;
}

