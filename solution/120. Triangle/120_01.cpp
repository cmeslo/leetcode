class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        
        int h = triangle.size();
        int ans = INT_MAX;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (i == 1) {
                    triangle[i][j] += triangle[i - 1][0];
                } else if (i > 1) {
                    if (j == 0)
                        triangle[i][j] += triangle[i - 1][0];
                    else if (j == i)
                        triangle[i][j] += triangle[i - 1][j - 1];
                    else
                        triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                    
                }
                if (i == h - 1) ans = min(ans, triangle[i][j]);
            }
        }
        
        return ans;
    }
};
