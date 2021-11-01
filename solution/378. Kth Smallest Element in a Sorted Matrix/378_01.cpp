typedef pair<int, int> PII;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        auto cmp = [&](PII& a, PII& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<PII, vector<PII>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        pq.emplace(0, 0);
        
        while (--k) {
            auto [y, x] = pq.top(); pq.pop();
            if (y + 1 < m && !visited[y + 1][x]) {
                visited[y + 1][x] = true;
                pq.emplace(y + 1, x);
            }
            if (x + 1 < n && !visited[y][x + 1]) {
                visited[y][x + 1] = true;
                pq.emplace(y, x + 1);
            }
        }
        
        return matrix[pq.top().first][pq.top().second];
    }
};
