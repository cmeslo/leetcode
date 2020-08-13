class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        int ans = 0;
        
        queue<pair<int, int>> q;
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (grid[y][x] == 2) {
                    grid[y][x] = 0;
                    q.push({y, x});
                }
        
        while (!q.empty()) {
            int size = q.size();
            ans++;
            while (size--) {
                auto cur = q.front(); q.pop();
                for (const auto& dir : dirs) {
                    int next_y = cur.first + dir[0], next_x = cur.second + dir[1];
                    if (next_y >= 0 && next_y < h && next_x >= 0 && next_x < w && grid[next_y][next_x] == 1) {
                        grid[next_y][next_x] = 0;
                        q.push({next_y, next_x});
                    }
                }      
            }
        }
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (grid[y][x] == 1) return -1;
        
        return ans == 0 ? 0 : ans - 1;
    }

private:
    const vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};
