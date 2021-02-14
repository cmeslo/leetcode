class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        int h = matrix.size(), w = matrix[0].size();
        
        vector<int> ans(h * w);
        int index = 0;
        bool dir = false;
        
        for (int y = 0; y < h; ++y) {
            int i = y, j = 0;
            int start = index;
            while (i >= 0 && i < h && j >= 0 && j < w) {
                ans[index++] = matrix[i--][j++];
            }
            if (dir) reverse(begin(ans) + start, begin(ans) + index);
            dir = !dir;
        }
        
        for (int x = 1; x < w; ++x) {
            int i = h - 1, j = x;
            int start = index;
            while (i >= 0 && i < h && j >= 0 && j < w) {
                ans[index++] = matrix[i--][j++];
            }
            if (dir) reverse(begin(ans) + start, begin(ans) + index);
            dir = !dir;
        }
        
        return ans;
    }
};
