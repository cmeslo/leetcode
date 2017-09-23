class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int n = matrix[0].size(), res = 0;
        vector<int> height(n, 0), left(n, 0), right(n, n);
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < n; ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            
            int curLeft = 0;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0; curLeft = j + 1;
                }
            }
            
            int curRight = n;
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = n; curRight = j;
                }
            }
            
            for (int j = 0; j < n; ++j) {
                res = max(res, (right[j] - left[j]) * height[j]);
            }
        }
        
        return res;
    }
};
