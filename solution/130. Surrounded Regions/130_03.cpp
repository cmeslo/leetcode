class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
private:
    const vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int m, n;
    
    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (board[x][y] != 'O') return;
        
        board[x][y] = '#';
        for (const auto& dir : dirs) {
            dfs(board, x + dir[0], y + dir[1]);
        }
    }
};
