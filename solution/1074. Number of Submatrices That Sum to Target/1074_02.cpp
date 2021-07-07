class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m; ++i)
            for (int j = 1; j < n; ++j)
                matrix[i][j] += matrix[i][j - 1];
        
        int ans = 0;
        unordered_map<int, int> prefix_sum;
        for (int L = 0; L < n; ++L) {
            for (int R = L; R < n; ++R) {
                prefix_sum = {{0, 1}};
                int sum = 0;
                for (int y = 0; y < m; ++y) {
                    sum += matrix[y][R] - (L > 0 ? matrix[y][L - 1] : 0);
                    ans += prefix_sum[sum - target];
                    prefix_sum[sum]++;
                }
            }
        }
        return ans;
    }
};
