class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> degree(n); // inDegree, index
        for (int i = 0; i < n; ++i)
            degree[i].second = i;
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            degree[a].first++;
            degree[b].first++;
        }
        sort(degree.begin(), degree.end());
        
        vector<int> values(n);
        for (int i = 0; i < n; ++i)
            values[degree[i].second] = i + 1;
        
        long res = 0;
        for (auto& r : roads)
            res += values[r[0]] + values[r[1]];
        return res;
    }
};
