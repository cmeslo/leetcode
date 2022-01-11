# 36. Valid Sudoku

## Solution 1

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 1. check rows and columns
        for (int i = 0; i < n; ++i) {
            if (!checkRowsAndCols(board, i))
                return false;
        }
        // 2. check 3 x 3 sub-boxes
        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                if (!checkSubBox(board, i, j))
                    return false;
            }
        }
        return true;
    }
    
private:
    int n = 9;
    
    bool checkRowsAndCols(vector<vector<char>>& board, int i) {
        vector<int> c1(n + 1), c2(n + 1);
        for (int y = 0; y < n; ++y) {
            if (board[y][i] == '.') continue;
            if (c1[board[y][i] - '0']++) return false;
        }
        for (int x = 0; x < n; ++x) {
            if (board[i][x] == '.') continue;
            if (c2[board[i][x] - '0']++) return false;
        }
        return true;
    }
    
    bool checkSubBox(vector<vector<char>>& board, int i, int j) {
        vector<int> c(n + 1);
        for (int y = i; y < i + 3; ++y) {
            for (int x = j; x < j + 3; ++x) {
                if (board[y][x] == '.') continue;
                if (c[board[y][x] - '0']++) return false;
            }
        }
        return true;
    }
};
```
