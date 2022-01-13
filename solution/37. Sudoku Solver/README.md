# 37. Sudoku Solver

## Solution 1

```cpp
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
