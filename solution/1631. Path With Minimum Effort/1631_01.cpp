class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& H) {
        int h = H.size(), w = H[0].size();
        vector<int> dirs = {0, -1, 0, 1, 0};
        auto bfs = [&](int cost) -> bool {
            queue<pair<int, int>> q;
            vector<int> seen(h * w);
            q.emplace(0, 0);
            seen[0] = 1;
            while (!q.empty()) {
                auto [cy, cx] = q.front(); q.pop();
                if (cy == h - 1 && cx == w - 1) return true;
                for (int i = 0; i < 4; ++i) {
                    int y = cy + dirs[i];
                    int x = cx + dirs[i + 1];
                    if (y < 0 || y >= h || x < 0 || x >= w) continue;
                    if (abs(H[cy][cx] - H[y][x]) > cost) continue;
                    if (seen[y * w + x]) continue;
                    seen[y * w + x] = 1;
                    q.emplace(y, x);
                }
            }
            return false;
        };
        
        int l = 0, r = 1e6 + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (bfs(m))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
