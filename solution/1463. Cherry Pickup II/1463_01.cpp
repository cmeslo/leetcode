class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        
        vector<vector<vector<int>>> cache(h, vector<vector<int>>(w, vector<int>(w, -1)));
        
        function<int(int, int, int)> dp = [&](int y, int x1, int x2) {
            if (y < 0 || y >= h || x1 < 0 || x1 >= w || x2 < 0 || x2 >= w) return 0;
            int& ans = cache[y][x1][x2];
            if (ans != -1) return ans;
            
            const int cur = grid[y][x1] + (x1 != x2) * grid[y][x2];
            for (int d1 = -1; d1 <= 1; ++d1)
                for (int d2 = -1; d2 <= 1; ++d2)
                    ans = max(ans, cur + dp(y + 1, x1 + d1, x2 + d2));
            
            return ans;
        };
        
        return dp(0, 0, w - 1);
    }
};
