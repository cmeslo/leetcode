class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!(i==0 || i==m-1 || j==0 || j==n-1)) continue; // not border
                if (board[i][j] != 'O') continue;
                
                // bfs
                queue<vector<int>> q;
                q.push(vector<int>{i, j});
                while (!q.empty()) {
                    auto front = q.front(); q.pop();
                    int x = front[0], y = front[1];
                    board[x][y] = '@';
                    
                    // up
                    if (x-1 >= 0 && board[x-1][y] == 'O') {
                        board[x-1][y] = '@';
                        q.push(vector<int>{x-1, y});
                    }
                    // down
                    if (x+1 < m && board[x+1][y] == 'O') {
                        board[x+1][y] = '@';
                        q.push(vector<int>{x+1, y});
                    }
                    // left
                    if (y-1 >= 0 && board[x][y-1] == 'O') {
                        board[x][y-1] = '@';
                        q.push(vector<int>{x, y-1});
                    }
                    // right
                    if (y+1 < n && board[x][y+1] == 'O') {
                        board[x][y+1] = '@';
                        q.push(vector<int>{x, y+1});
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j]=='@'? 'O' : 'X';
            }
        }
    }
};
