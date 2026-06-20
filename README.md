# C++ Internship Tasks

A collection of small console-based C++ games built as part of my internship tasks. Each one focuses on different core C++ concepts — loops, arrays, 2D arrays, randomization, and basic game logic.

## Projects

### 🔴 Connect Four — `game.cpp`
A two-player Connect Four game played in the console. Players take turns dropping discs into columns, and the game checks for horizontal, vertical, and diagonal wins on a 6x7 board.

**Concepts used:** 2D arrays, classes, win-condition checking

### 🔢 Guess the Number — `game2.cpp`
The classic number-guessing game. The program picks a random number between 1 and 100, and the player tries to guess it with "too high / too low" hints.

**Concepts used:** random number generation, loops, conditionals

### ✊ Rock Paper Scissors — `game33.cpp`
Player vs computer Rock-Paper-Scissors. The computer's move is randomly generated, and the game keeps replaying on a draw.

**Concepts used:** preprocessor constants, random number generation, conditionals

### ⭕ Tic-Tac-Toe vs AI — `game_4.cpp`
Player (X) vs a simple AI (O) that picks random valid moves. Checks rows, columns, and diagonals for a win, and detects draws.

**Concepts used:** 2D arrays, functions, win/draw detection, basic AI logic

## How to Compile & Run

Each game is a standalone file. Compile with g++ (or any C++ compiler):

```bash
g++ game.cpp -o connect_four
./connect_four
```

```bash
g++ game2.cpp -o guess_number
./guess_number
```

```bash
g++ game33.cpp -o rock_paper_scissors
./rock_paper_scissors
```

```bash
g++ game_4.cpp -o tic_tac_toe
./tic_tac_toe
```

## Tech Used

- C++ (standard library only — `iostream`, `cstdlib`, `ctime`).
- No external dependencies.



These were completed as part of my internship to practice core C++ concepts including OOP, arrays, and game logic.
