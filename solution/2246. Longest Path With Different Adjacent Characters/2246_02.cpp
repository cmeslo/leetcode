class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        vector<int> inD(n);

        for (int i = 1; i < n; ++i) {
            if (s[i] == s[parent[i]]) continue;
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
            inD[parent[i]]++;
            inD[i]++;
        }

        vector<int> cnt(n, 1);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inD[i] == 1) {
                q.push(i);
            }
        }

        int res = 1;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            --inD[node];
            for (int next : adj[node]) {
                if (inD[next] == 0) continue;
                res = max(res, cnt[node] + cnt[next]);
                cnt[next] = max(cnt[next], cnt[node] + 1);
                if (--inD[next] == 1) {
                    q.push(next);
                }
            }
        }

        return res;
    }
};
