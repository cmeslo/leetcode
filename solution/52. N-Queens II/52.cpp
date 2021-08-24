class Solution {
public:
    int totalNQueens(int n) {
        cols_.resize(n);
        diag1_.resize(n * 2 - 1);
        diag2_.resize(n * 2 - 1);
        dfs(n, 0);
        return ans_;
    }
    
private:
    vector<bool> cols_;
    vector<bool> diag1_;
    vector<bool> diag2_;
    int ans_;
    
    void dfs(int n, int y) {
        if (y == n) {
            ++ans_;
            return;
        }
        
        for (int x = 0; x < n; ++x) {
            if (cols_[x] || diag1_[x + y] || diag2_[x - y + n - 1]) continue;
            cols_[x] = true;
            diag1_[x + y] = true;
            diag2_[x - y + n - 1] = true;
            dfs(n, y + 1);
            cols_[x] = false;
            diag1_[x + y] = false;
            diag2_[x - y + n - 1] = false;
        }
    }
};
