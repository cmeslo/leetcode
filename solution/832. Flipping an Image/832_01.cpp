class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty()) return {};
        
        int h = A.size(), w = A[0].size();
        vector<vector<int>> B(h, vector<int>(w));
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                B[y][w - 1 - x] = 1 - A[y][x];
        
        return B;
    }
};
