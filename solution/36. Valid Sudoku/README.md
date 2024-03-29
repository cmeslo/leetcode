# 36. Valid Sudoku

## Solution 1: Brute force

```cpp
// Runtime: 53 ms

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

## Solution 2: Bit mask (推薦)

```cpp
// Runtime: 20 ms

bool isValidSudoku(vector<vector<char>>& board) {
    int n = 9;
    vector<int> rows(n), cols(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '.') continue;
            int mask = 1 << (board[i][j] - '0');
            if (rows[i] & mask) return false;
            if (cols[j] & mask) return false;
            rows[i] |= mask;
            cols[j] |= mask;
        }
    }

    for (int i = 0; i < n; i += 3) {
        for (int j = 0; j < n; j += 3) {
            int box = 0;
            for (int y = i; y < i + 3; ++y) {
                for (int x = j; x < j + 3; ++x) {
                    if (board[y][x] == '.') continue;
                    int mask = 1 << (board[y][x] - '0');
                    if (box & mask) return false;
                    box |= mask;
                }
            }
        }
    }

    return true;
}
```
