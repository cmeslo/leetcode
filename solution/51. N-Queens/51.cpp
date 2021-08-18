class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        board_.resize(n, string(n, '.'));
        cols_.resize(n, 0);
        diag1_.resize(n + n - 1, 0);
        diag2_.resize(n + n - 1, 0);
        dfs(0, n);
        return ans_;
    }
    
private:
    vector<vector<string>> ans_;
    vector<string> board_;
    vector<bool> cols_;
    vector<bool> diag1_;
    vector<bool> diag2_;
    
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
