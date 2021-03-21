// Your runtime beats 93.22 % of cpp submissions.

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int h = mat.size(), w = mat[0].size();
        int y = h - 1, x = 0;
        
        while (y >= 0 || x <= w - 1) {
            if (y < 0) {
                ++x;
                y = 0;
            }
            
            vector<int> tmp;
            for (int i = y, j = x; i < h && j < w; ++i, ++j)
                tmp.push_back(mat[i][j]);
            
            sort(begin(tmp), end(tmp));
            
            for (int i = y, j = x, cnt = 0; i < h && j < w && cnt < tmp.size(); ++i, ++j)
                mat[i][j] = tmp[cnt++];
            
            --y;
        }
        return mat;
    }
};
