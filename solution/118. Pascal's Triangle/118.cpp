class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        
        for (int i = 0; i < numRows; ++i) {
            vector<int> cur(i + 1);
            cur[0] = cur[i] = 1;
            for (int j = 1; j < i; ++j) {
                cur[j] += res[i - 1][j - 1] + res[i - 1][j];
            }
            res[i] = cur;
        }
        
        return res;
    }
};

// 0 1 2 3
// 1
// 1 1
// 1 2 1
// 1 3 3 1

// res[i][j] = res[i - 1][j - 1] + res[i - 1][j]
