class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int res = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j) {
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            res = max(res, maxInRow(height));
        }
        return res;
    }
    
    int maxInRow(vector<int>& height) {
        int res = 0;
        stack<int> s;
        height.push_back(0);
        
        for (int i = 0; i < height.size(); ++i)
        {
            if (s.empty() || height[s.top()] <= height[i]) {
                s.push(i);
            } else {
                int cur = s.top(); s.pop();
                int len = s.empty() ? i : i - s.top() - 1;
                res = max(res, height[cur] * len);
                --i;
            }
        }
        return res;
    }
};
