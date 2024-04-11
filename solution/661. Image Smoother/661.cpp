class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        const int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0, sum = 0;
                for (int y = max(0, i - 1); y < min(m, i + 2); ++y) {
                    for (int x = max(0, j - 1); x < min(n, j + 2); ++x) {
                        cnt += 1;
                        sum += img[y][x];
                    }
                }
                res[i][j] = sum / cnt;
            }
        }
        return res;
    }
};
