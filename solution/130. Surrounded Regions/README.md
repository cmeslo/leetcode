# 130. Surrounded Regions

## Solution 1: BFS

### 寫法一：130_01.cpp

```cpp
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
```

### 寫法二：130_02.cpp

```cpp
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
```

## Solution 2: DFS

### 130_03.cpp

dfs, 寫得比較簡潔

```cpp
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
```
