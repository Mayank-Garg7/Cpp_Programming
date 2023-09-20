#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the game board
void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        vector<char> row(3, ' ');
        board.push_back(row);
    }
}

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -+-+-" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal 1
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Diagonal 2
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board;
    initializeBoard(board);

    char currentPlayer = 'X';
    bool gameWon = false;
    bool draw = false;

    cout << "Welcome to Tic Tac Toe!" << endl;

    while (!gameWon && !draw) {
        displayBoard(board);

        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;

        // Check for a win or draw
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            gameWon = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw! The game is over." << endl;
            draw = true;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
