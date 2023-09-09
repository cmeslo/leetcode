class Solution {
public:
    int numberOfArrays(string s, int k) {
        n = s.size();
        memo.resize(n, -1);
        return dp(s, 0, k);
    }
    
private:
    const int M = 1e9 + 7;
    vector<int> memo;
    int n;
    
    int dp(const string& s, int i, int k) {
        if (i == n) return 1;
        if (s[i] == '0') return 0;
        if (memo[i] != -1) return memo[i];
        
        int res = 0;
        long x = 0;
        for (int j = i; j < n; ++j) {
            x = x * 10 + s[j] - '0';
            if (x > k) break;
            res = (res + dp(s, j + 1, k)) % M;
        }
        return memo[i] = res;
    }
};
