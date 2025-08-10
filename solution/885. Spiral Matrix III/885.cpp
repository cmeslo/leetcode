class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int y, int x) {
        vector<vector<int>> res = {{y, x}};
        int dy = 0, dx = 1;
        for (int n = 0; res.size() < rows * cols; ++n) {
            for (int i = 0; i < n / 2 + 1; ++i) {
                y += dy, x += dx;
                if (0 <= y && y < rows && 0 <= x && x < cols)
                    res.push_back({y, x});
            }
            // x, y = y, -x
            swap(dy, dx);
            dx = -dx;
        }
        return res;
    }
};
