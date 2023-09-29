class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1;
        int left = 0, right = n - 1;
        int size = m * n;
        
        vector<int> res;
        while (res.size() < size) {
            for (int j = left; j <= right && res.size() < size; ++j)
                res.push_back(matrix[up][j]);
            
            for (int i = up + 1; i <= down - 1 && res.size() < size; ++i)
                res.push_back(matrix[i][right]);
            
            for (int j = right; j >= left && res.size() < size; --j)
                res.push_back(matrix[down][j]);
            
            for (int i = down - 1; i >= up + 1 && res.size() < size; --i)
                res.push_back(matrix[i][left]);
            
            up++; right--; down--; left++;
        }
        return res;
    }
};
