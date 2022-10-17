class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;
        int y = 0, x = -1;
        for (int i = 1; i <= n * n; ++i) {
            int next_y = y + dirs[d][0];
            int next_x = x + dirs[d][1];
            // 因為下一步會走出邊界、或者已經走過，所以要轉方向
            if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n|| ans[next_y][next_x] != 0)
                d = (d + 1) % 4;
            y = y + dirs[d][0];
            x = x + dirs[d][1];
            ans[y][x] = i;
        }
        return ans;
    }
};
