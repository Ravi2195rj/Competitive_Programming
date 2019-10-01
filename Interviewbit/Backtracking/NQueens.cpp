/*

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/


bool isSafe(vector<string> &board, int n, int x, int y) {
    for(int i = 0; i < n; i++) {
        if(i == x) {
            continue;
        }
        if(board[i][y] == 'Q') {
            return false;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i == y) {
            continue;
        }
        if(board[x][i] == 'Q') {
            return false;
        }
    }
    int i = 0;
    while(x-i >= 0 && y-i >= 0) {
        if(x-i != x && y-i != y) {
            if(board[x-i][y-i] == 'Q') {
                return false;
            }
        }
        i++;
    }
    i = 0;
    while(x-i >= 0 && y+i < n) {
        if(x-i != x && y+i != y) {
            if(board[x-i][y+i] == 'Q') {
                return false;
            }
        }
        i++;
    }
    i = 0;
    while(x+i < n && y-i >= 0) {
        if(x+i != x && y-i != y) {
            if(board[x+i][y-i] == 'Q') {
                return false;
            }
        }
        i++;
    }
    i = 0;
    while(x+i < n && y+i < n) {
        if(x+i != x && y+i != y) {
            if(board[x+i][y+i] == 'Q') {
                return false;
            }
        }
        i++;
    }
    return true;
}

void NQueens(vector<vector<string>> &res, vector<string> &board, int r, int n) {
    if(r == n) {
        res.push_back(board);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(isSafe(board, n, r, i)) {
            board[r][i] = 'Q';
            NQueens(res, board, r+1, n);
            board[r][i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int n) {
    if(n == 0) {
        return {};
    }
    if(n == 1) {
        return {{"Q"}};
    }
    string row(n, '.');
    vector<string> board(n, row);
    vector<vector<string>> res;
    NQueens(res, board, 0, n);
    return res;
}