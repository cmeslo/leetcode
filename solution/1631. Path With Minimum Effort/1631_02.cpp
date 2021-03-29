class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int h = heights.size(), w = heights[0].size();
        vector<int> dirs = {0, -1, 0, 1, 0};
        vector<int> dist(h * w, INT_MAX);
        dist[0] = 0;
        using Node = pair<int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> q;
        q.emplace(0, 0);
        
        while (!q.empty()) {
            auto [diff, index] = q.top(); q.pop();
            if (index == h * w - 1) return diff;
            if (dist[index] < diff) continue;
            int y = index / w;
            int x = index % w;
            for (int i = 0; i < 4; ++i) {
                int ny = y + dirs[i];
                int nx = x + dirs[i + 1];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
                int next_index = ny * w + nx;
                int next_diff = max(diff, abs(heights[y][x] - heights[ny][nx]));
                if (next_diff >= dist[next_index]) continue;
                q.emplace(dist[next_index] = next_diff, next_index);
            }
        }
        return -1;
    }
};
