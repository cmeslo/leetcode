class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        pre_.resize(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                pre_[i][j] = matrix[i - 1][j - 1] + pre_[i - 1][j] + pre_[i][j - 1] - pre_[i - 1][j - 1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1; ++col1; ++row2; ++col2;
        return pre_[row2][col2]
            - pre_[row1 - 1][col2]
            - pre_[row2][col1 - 1]
            + pre_[row1 - 1][col1 - 1];
    }
    
private:
    vector<vector<int>> pre_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int parapre_1 = obj->sumRegion(row1,col1,row2,col2);
 */
