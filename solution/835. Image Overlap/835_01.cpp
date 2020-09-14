class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        h = A.size(), w = A[0].size();
        
        int ans = 0;
        for (int offsetY = 0; offsetY < h; ++offsetY)
            for (int offsetX = 0; offsetX < w; ++offsetX)
                ans = max(ans, max(countOverlap(A, B, offsetY, offsetX),
                                   countOverlap(B, A, offsetY, offsetX)));
        
        return ans;
    }
    
private:
    int h, w;
    
    int countOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int offsetY, int offsetX) {
        int cnt = 0;
        for (int y = offsetY; y < h; ++y)
            for (int x = offsetX; x < w; ++x)
                cnt += A[y - offsetY][x - offsetX] * B[y][x];
        
        return cnt;
    }
};
