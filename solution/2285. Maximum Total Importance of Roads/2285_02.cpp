class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            degree[a]++;
            degree[b]++;
        }
        sort(degree.begin(), degree.end());
        
        long res = 0;
        for (int i = 0; i < n; ++i)
            res += 1L * degree[i] * (i + 1);
        return res;
    }
};
