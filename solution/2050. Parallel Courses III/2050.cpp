class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for (auto& r : relations) {
            adj[r[0] - 1].push_back(r[1] - 1);
            ++inDegree[r[1] - 1];
        }

        queue<int> q;
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = time[i];
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int next : adj[node]) {
                dp[next] = max(dp[next], dp[node] + time[next]);
                if (--inDegree[next] == 0)
                    q.push(next);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
