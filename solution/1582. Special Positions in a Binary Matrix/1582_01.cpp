class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        h = mat.size(), w = mat[0].size();
        int ans = 0;
        
        for (int y = 0; y < h; ++y)
            for (int x = 0; x < w; ++x)
                if (mat[y][x] == 1 && isSpecial(mat, y, x))
                    ++ans;
        
        return ans;
    }
    
private:
    int h, w;
    
    bool isSpecial(vector<vector<int>>& mat, int y, int x) {
        for (int i = y - 1; i >= 0; --i)
            if (mat[i][x]) return false;
        
        for (int i = y + 1; i < h; ++i)
            if (mat[i][x]) return false;
        
        for (int i = x - 1; i >= 0; --i)
            if (mat[y][i]) return false;
        
        for (int i = x + 1; i < w; ++i)
            if (mat[y][i]) return false;
        
        return true;
    }
};
