/* 
Problem - C Tic-tac-toe
*/

#include <iostream>
#include <vector>
using namespace std;

bool checkWin(const vector<string>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}

int main() {
    vector<string> board(3);
    int xCount = 0, oCount = 0;
    
    // Read the board and count 'X' and '0'
    for (int i = 0; i < 3; ++i) {
        cin >> board[i];
        for (char cell : board[i]) {
            if (cell == 'X') xCount++;
            else if (cell == '0') oCount++;
        }
    }
    
    // Check if counts are valid
    if (xCount < oCount || xCount > oCount + 1) {
        cout << "illegal" << endl;
        return 0;
    }
    
    bool xWins = checkWin(board, 'X');
    bool oWins = checkWin(board, '0');
    
    // Determine the result based on the conditions
    if (xWins && oWins) {
        cout << "illegal" << endl;
    } else if (xWins) {
        if (xCount == oCount + 1) cout << "the first player won" << endl;
        else cout << "illegal" << endl;
    } else if (oWins) {
        if (xCount == oCount) cout << "the second player won" << endl;
        else cout << "illegal" << endl;
    } else if (xCount + oCount == 9) {
        cout << "draw" << endl;
    } else {
        if (xCount == oCount) cout << "first" << endl;
        else cout << "second" << endl;
    }
    
    return 0;
}
