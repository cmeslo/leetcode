class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for (int y1 = 0; y1 < m; ++y1) {
            vector<int> rows(n);
            for (int y2 = y1; y2 < m; ++y2) {
                unordered_map<int, int> freq;
                freq[0] = 1;
                int sum = 0;
                for (int x = 0; x < n; ++x) {
                    rows[x] += matrix[y2][x];
                    sum += rows[x];
                    ans += freq[sum - target];
                    freq[sum]++;
                }
            }
        }
        return ans;
    }
};
