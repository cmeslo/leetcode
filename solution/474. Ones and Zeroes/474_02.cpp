class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->m = m;
        this->n = n;
        this->len = strs.size();
        memo.resize(len, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        
        vector<pair<int, int>> A(len);
        for (int i = 0; i < len; ++i) {
            int ones = 0, zeros = 0;
            for (char& c : strs[i]) {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }
            A[i] = {zeros, ones};
        }
        return dfs(A, 0, 0, 0);
    }
    
private:
    int len;
    int m, n;
    vector<vector<vector<int>>> memo;
    
    int dfs(vector<pair<int, int>>& A, int i, int zeros, int ones) {
        if (i == len) return 0;
        if (memo[i][zeros][ones] != -1) return memo[i][zeros][ones];
        
        int count = dfs(A, i + 1, zeros, ones);
        if (zeros + A[i].first <= m && ones + A[i].second <= n)
            count = max(count, dfs(A, i + 1, zeros + A[i].first, ones + A[i].second) + 1);
        
        return memo[i][zeros][ones] = count;
    }
};

// 10 0001 111001 1 0
//            i

// dfs(i + 1, zeros, ones, cur, ans)
// dfs(i + 1, zeros + 2, ones + 4, cur + 1, ans)
