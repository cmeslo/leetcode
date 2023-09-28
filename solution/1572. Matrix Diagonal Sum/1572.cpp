class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += mat[i][i];
            res += mat[i][n - 1 - i];
        }
        return res - (n % 2 ? mat[n / 2][n / 2] : 0);
    }
};
