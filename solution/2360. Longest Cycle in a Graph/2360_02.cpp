class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> D(n);
        for (int x : edges)
            if (x != -1)
                D[x]++;
        
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (D[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            int next = edges[node];
            if (next != -1 && --D[next] == 0)
                q.push(next);
        }
        
        int res = -1;
        for (int i = 0; i < n; ++i) {
            if (D[i] == 0) continue;
            int cnt = 1;
            D[i] = 0;
            for (int j = edges[i]; j != i; j = edges[j]) {
                D[j] = 0;
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};
