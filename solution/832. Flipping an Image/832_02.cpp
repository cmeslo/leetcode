class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if (A.empty()) return {};
        
        int h = A.size(), w = A[0].size();
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x * 2 < w; ++x)
                if (A[y][x] == A[y][w - 1 - x])
                    A[y][x] = A[y][w - 1 - x] ^= 1;
        
        return A;
    }
};
