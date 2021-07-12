class Solution {
public:
    int minimumTotal(vector<vector<int>>& T) {
        int n = T.size();
        
        for (int i = n - 2; i >= 0; --i)
            for (int j = 0; j <= i; ++j)
                T[i][j] += min(T[i + 1][j], T[i + 1][j + 1]);
        
        return T[0][0];
    }
};
