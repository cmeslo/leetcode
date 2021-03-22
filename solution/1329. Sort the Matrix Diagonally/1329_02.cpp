class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int h = mat.size(), w = mat[0].size();
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                m[i - j].push(mat[i][j]);
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                mat[i][j] = m[i - j].top(); m[i - j].pop();
            }
        }
        
        return mat;
    }
};
