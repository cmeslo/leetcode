class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int h = mat.size(), w = mat[0].size();
        vector<int> rows(h, 0), cols(w, 0);
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (mat[y][x] == 1)
                    ++rows[y], ++cols[x];
        
        int ans = 0;
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (mat[y][x] == 1 && rows[y] == 1 && cols[x] == 1)
                    ++ans;
        
        return ans;
    }
};
