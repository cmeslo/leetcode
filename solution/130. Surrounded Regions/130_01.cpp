class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const vector<int> dirs = {0, -1, 0, 1, 0};
        int m = board.size(), n = board[0].size();
        
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                q.push({i, n - 1});
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                q.push({m - 1, j});
            }
        }
        
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int y = i + dirs[k];
                int x = j + dirs[k + 1];
                if (y <= 0 || y >= m - 1 || x <= 0 || x >= n - 1 || board[y][x] != 'O') continue;
                board[y][x] = '#';
                q.push({y, x});
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
