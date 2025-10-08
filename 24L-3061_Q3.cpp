#include <iostream>
using namespace std;


void displayBoard(char board[3][3]);
bool makeMove(char board[3][3], int row, int col, char player);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);


int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    cout << "-------------------------------------------\n";
    cout << "            TIC - TAC - TOE            \n";
    cout << "-------------------------------------------\n";
    cout << "Player 1: X\nPlayer 2: O\n\n";

    displayBoard(board);

    // Main game loop
    for (int turn = 0; turn < 9 && !gameOver; turn++)
    {
        cout << "Player " << currentPlayer << ", enter row and column (1-3): ";
        cin >> row >> col;

        // Adjust for 0-based indexing
        row--;
        col--;

        // Validate move
        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            cout << "Invalid position! Try again.\n";
            turn--;
            continue;
        }

        //filling already filled part
        if (!makeMove(board, row, col, currentPlayer))
        {
            cout << "That cell is already taken! Try again.\n";
            turn--;
            continue;
        }

        // Show updated board
        displayBoard(board);

        // Check for a win
        if (checkWin(board, currentPlayer))
        {
            cout << " Player " << currentPlayer << " wins! " << endl;
            gameOver = true;
            break;
        }

        // Check for draw
        if (checkDraw(board))
        {
            cout << " Game Drawn!" << endl;
            gameOver = true;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (!gameOver)
        cout << " Game Drawn!" << endl;

    return 0;
}

void displayBoard(char board[3][3])
{
    cout << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Make a move if cell empty
bool makeMove(char board[3][3], int row, int col, char player)
{
    if (board[row][col] == ' ')
    {
        board[row][col] = player;
        return true;
    }
    return false;
}

// Check for a win
bool checkWin(char board[3][3], char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

// Check for draw (no empty spaces)
bool checkDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}
