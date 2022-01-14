# 37. Sudoku Solver

## Solution 1: DFS

```cpp
// Your runtime beats 97.94 % of cpp submissions.
// Your memory usage beats 82.43 % of cpp submissions.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows_, 0, sizeof(rows_));
        memset(cols_, 0, sizeof(cols_));
        memset(boxes_, 0, sizeof(boxes_));
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                fillNum(board, i, j, board[i][j], 1);
            }
        }
        
        dfs(board, 0, 0);
    }
    
private:
    int rows_[9][256], cols_[9][256];
    int boxes_[3][3][256];
    
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return dfs(board, i + 1, 0);
        if (board[i][j] != '.') return dfs(board, i, j + 1);
        
        for (char k = '1'; k <= '9'; ++k) {
            if (isValid(i, j, k)) {
                fillNum(board, i, j, k, 1);
                if (dfs(board, i, j + 1)) return true;
                fillNum(board, i, j, k, 0);
            }
        }
        
        return false;
    }
    
    bool isValid(int i, int j, int val) {
        return rows_[i][val] != 1
            && cols_[j][val] != 1
            && boxes_[i / 3][j / 3][val] != 1;
    }
    
    void fillNum(vector<vector<char>>& board, int i, int j, char val, int flag) {
        rows_[i][val] = cols_[j][val] = boxes_[i/3][j/3][val] = flag;
        board[i][j] = flag ? val : '.';
    }
};
```

## Solution 2: DFS

### 解釋

使用 bit mask

```
00 01 02, 03 04 05, 06 07 08
10 11 12, 13 14 15, 16 17 18
20 21 22, 23 24 25, 26 27 28

30 31 32, 33 34 35, 36 37 38
...
```

把 box 看成

```
0, 1, 2
3, 4, 5
6, 7, 8
```

```boxes[i / 3 * 3 + j / 3]```

### Code

```cpp
// Your runtime beats 86.57 % of cpp submissions.
// Your memory usage beats 82.43 % of cpp submissions.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(n), cols.resize(n), boxes.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == '.') continue;
                int mask = 1 << (board[i][j] - '0');
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[i / 3 * 3 + j / 3] |= mask;
            }
        }
        
        dfs(board, 0, 0);
    }
    
private:
    int n = 9;
    vector<int> rows, cols, boxes;
    
    bool dfs(vector<vector<char>>& board, int y, int x) {
        if (y == n) return true;
        if (x == n) return dfs(board, y + 1, 0);
        if (board[y][x] != '.') return dfs(board, y, x + 1);
        
        int boxIndex = y / 3 * 3 + x / 3;
        for (int k = 1; k <= 9; ++k) {
            int mask = 1 << k;
            if ((rows[y] & mask) != 0 || (cols[x] & mask) != 0 || (boxes[boxIndex] & mask) != 0)
                continue;
            rows[y] |= mask;
            cols[x] |= mask;
            boxes[boxIndex] |= mask;
            board[y][x] = k + '0';
            if (dfs(board, y, x + 1)) return true;
            board[y][x] = '.';
            rows[y] ^= mask;
            cols[x] ^= mask;
            boxes[boxIndex] ^= mask;
        }
        return false;
    }
};
```
