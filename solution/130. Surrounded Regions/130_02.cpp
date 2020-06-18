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
                queue<int> q;
                q.push(i*n + j);
                while (!q.empty()) {
                    int cur = q.front(); q.pop();
                    int x = cur/n, y = cur%n;
                    board[x][y] = '@';
                    
                    // up
                    if (x-1 >= 0 && board[x-1][y] == 'O') {
                        board[x-1][y] = '@';
                        q.push(cur-n);
                    }
                    // down
                    if (x+1 < m && board[x+1][y] == 'O') {
                        board[x+1][y] = '@';
                        q.push(cur+n);
                    }
                    // left
                    if (y-1 >= 0 && board[x][y-1] == 'O') {
                        board[x][y-1] = '@';
                        q.push(cur-1);
                    }
                    // right
                    if (y+1 < n && board[x][y+1] == 'O') {
                        board[x][y+1] = '@';
                        q.push(cur+1);
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
