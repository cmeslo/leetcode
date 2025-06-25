class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> res(k, vector<int>(k));
        
        auto row = calc(rowConditions, k);
        if (row.empty()) return {};
        auto col = calc(colConditions, k);
        if (col.empty()) return {};
        reverse(col.begin(), col.end());
        
        unordered_map<int, int> val2row;
        int i = 0, j = 0;
        for (int i = 0; i < k; ++i) {
            int val = row[i];
            res[i][0] = val;
            val2row[val] = i;
        }
        
        j = k - 1;
        for (int i = 0; i < k; ++i) {
            int val = col[i];
            int y = val2row[val];
            res[y][0] = 0;
            res[y][j--] = val;
        }
        
        return res;
    }
    
private:
    vector<int> calc(vector<vector<int>> cond, int k) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> inDegree;
        for (auto& c : cond) {
            int a = c[0], b = c[1];
            adj[a].push_back(b);
            inDegree[a];
            inDegree[b]++;
        }
        
        vector<int> res;
        queue<int> q;
        for (auto& [val, d] : inDegree) {
            if (d == 0)
                q.push(val);
        }
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front(); q.pop();
                res.push_back(node);
                for (int next : adj[node]) {
                    if (--inDegree[next] == 0) {
                        q.push(next);
                    }
                }
            }
        }
        
        for (int i = 1; i <= k; ++i) {
            if (!inDegree.count(i))
                res.push_back(i);
            if (inDegree[i] != 0)
                return {};
        }
        return res;
    }
};
