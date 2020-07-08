class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        h = grid.size(), w = grid[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 1) return bfs(grid, i*w+j);
            }
        }
        return 0;
    }

private:
    const vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int h, w;

    int bfs(vector<vector<int>>& grid, int root) {
        int cnt = 0;
        queue<int> q;
        
        grid[root/w][root%w] = -1;
        q.push(root);
        
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            int y = cur / w, x = cur % w;
            for (const auto& dir : dirs) {
                int nextY = y + dir[0], nextX = x + dir[1];
                if (!isInGrid(nextY, nextX) || grid[nextY][nextX] == 0) {
                    cnt++; continue;
                }
                if (grid[nextY][nextX] == 1) {
                    grid[nextY][nextX] = -1;
                    q.push(nextY*w + nextX);
                }
            }
        }
        return cnt;
    }
    
    bool isInGrid(int y, int x) {
        return (0 <= y) && (y < h) && (0 <= x) && (x < w);
    }
};
