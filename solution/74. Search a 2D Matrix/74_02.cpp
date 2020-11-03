class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int h = matrix.size();
        int w = matrix[0].size();
        int l = 0, r = h * w;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            int val = matrix[mid / w][mid % w];
            if (val == target) return true;
            if (val < target)
                l = mid + 1;
            else
                r = mid;
        }
        
        return false;
    }
};
