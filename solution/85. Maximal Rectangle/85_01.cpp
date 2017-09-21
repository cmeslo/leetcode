class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0;
        vector<int> height(matrix[0].size(), 0);
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            res = max(res, maxRectangleInRow(height));
        }
        return res;
    }
    
    int maxRectangleInRow(vector<int>& height) {
        int res = 0;
        int n = height.size();
        
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && height[i] <= height[i + 1]) continue;
            
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                res = max(res, minHeight * (i - j + 1));
            }
        }
        return res;
    }
};
