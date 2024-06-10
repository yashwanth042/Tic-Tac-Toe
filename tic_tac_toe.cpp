#include <iostream>
using namespace std;

const int BOARD_SIZE = 3;
char board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < BOARD_SIZE; ++i) {
        cout << "| ";
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if the game is over (win/draw)
bool isGameOver() {
    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if ((board[i][0] != ' ') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])) {
            return true;
        }
        if ((board[0][i] != ' ') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] != ' ') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
        return true;
    }
    if ((board[0][2] != ' ') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])) {
        return true;
    }
    // Check for a draw
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false; // The game is not over yet
            }
        }
    }
    return true; // No empty spaces left, it's a draw
}

// Function to check if a move is valid
bool isValidMove(int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false; // Out of bounds
    }
    if (board[row][col] != ' ') {
        return false; // Cell already taken
    }
    return true;
}

// Function to get player input and make a move
void makeMove(char currentPlayer) {
    int row, col;
    do {
        cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2) separated by space: ";
        cin >> row >> col;
    } while (!isValidMove(row, col));
    board[row][col] = currentPlayer;
}

int main() {
    char currentPlayer = 'X';
    bool gameOver = false;

    initializeBoard();
    displayBoard();

    while (!gameOver) {
        makeMove(currentPlayer);
        displayBoard();
        gameOver = isGameOver();

        if (!gameOver) {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    if (currentPlayer == 'X') {
        cout << "Player O wins!" << endl;
    } else if (currentPlayer == 'O') {
        cout << "Player X wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
