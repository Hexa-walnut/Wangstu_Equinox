#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void initialize(char board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board[row][col] = ' ';
        }
    }
}

void print_board(char board[][COLS]) {
    cout << "     1   2   3  " << endl;
    cout << "   +---+---+---+" << endl;
    for (int row = 0; row < ROWS; row++) {
        cout << " " << row + 1 << " | ";
        for (int col = 0; col < COLS; col++) {
            cout << board[row][col] << " | ";
        }
        cout << endl << "   +---+---+---+" << endl;
    }
}

bool check_win(char board[][COLS], char player) {
    for (int row = 0; row < ROWS; row++) {
        if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
            return true;
        }
    }
    
    for (int col = 0; col < COLS; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    
    return false;
}

bool check_tie(char board[][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    
    return true;
}

void random_place(char board[][COLS], char computer) {
    while (true) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] == ' ') {
            board[row][col] = computer;
            break;
        }
    }
}

int main() {
    char board[ROWS][COLS];
    initialize(board);
    srand(time(NULL));
    
    char player = 'X';
    char computer = 'O';
    
    while (true) {
        print_board(board);
        
        if (player == 'X') {
            int row, col;
            cout << "Enter row and column (1-3) to place X: ";
            cin >> row >> col;
            row--;
            col--;
            
            if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != ' ') {
                cout << "Invalid move, try again." << endl;
                continue;
            }
            
            board[row][col] = player;
            if (check_win(board, player)) {
                cout << "You win!" << endl;
                break;
            }
            else if (check_tie(board)) {
                cout << "Tie!" << endl;
                break;
            }
            player = 'O';
        }
        else {
            random_place(board, computer);
            if (check_win(board, computer)) {
                print_board(board);
                cout << "You lose!" << endl;
                break;
            }
            else if (check_tie(board)) {
                print_board(board);
                cout << "Tie!" << endl;
                break;
            }
            player = 'X';
        }
    }
    
    return 0;
}

