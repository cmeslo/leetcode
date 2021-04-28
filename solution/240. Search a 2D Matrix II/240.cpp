class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        
        int y = m - 1, x = 0;
        while (y >= 0 && x < n) {
            if (matrix[y][x] == target)
                return true;
            else if (matrix[y][x] > target)
                --y;
            else
                ++x;
        }
        return false;
    }
};
