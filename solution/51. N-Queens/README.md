# 51. N-Queens

## Solution: Backtracking

### 解釋

從上往下、一行一行放置皇后，

同一行裡每一列都試試，

每放置一個皇后，把對應的 ```列```、```右下至左上對角線```，```左上至右下對角線``` 作標記，

```行```不需要標記，因為是從上往下放走，```行```不會重覆，

關鍵是如何把對角線做標記，標記為不能放置：

```cpp
diag1_.resize(2 * n - 1, 0);
diag2_.resize(2 * n - 1, 0);
diag1_[y + x]
diag2_[y - x + (n - 1)]
```

### Code

```cpp
// Your runtime beats 100.00 % of cpp submissions.
// Your memory usage beats 46.61 % of cpp submissions.

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board_.resize(n, string(n, '.'));
        cols_.resize(n, 0);
        diag1_.resize(2 * n - 1, 0);
        diag2_.resize(2 * n - 1, 0);
        dfs(0, n);
        return ans_;
    }
    
private:
    vector<vector<string>> ans_;
    vector<string> board_;
    vector<int> cols_;
    vector<int> diag1_;
    vector<int> diag2_;
    
    void dfs(int y, int n) {
        if (y == n) {
            ans_.push_back(board_);
            return;
        }
        
        for (int x = 0; x < n; ++x) {
            if (!isAvailable(y, x, n)) continue;
            updateBoard(y, x, n, true);
            dfs(y + 1, n);
            updateBoard(y, x, n, false);
        }
    }
    
    bool isAvailable(int y, int x, int n) {
        return !cols_[x]
            && !diag1_[y + x]
            && !diag2_[y - x + (n - 1)];
    }
    
    void updateBoard(int y, int x, int n, int is_put) {
        cols_[x] = is_put;
        diag1_[y + x] = is_put;
        diag2_[y - x + (n - 1)] = is_put;
        board_[y][x] = is_put ? 'Q' : '.';
    }
};
```
