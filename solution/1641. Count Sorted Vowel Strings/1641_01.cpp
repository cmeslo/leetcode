class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> mem(n + 1, vector<int>(6));
        return dp(n, 5, mem);
    }
    
private:
    int dp(int n, int remain, vector<vector<int>>& mem) {
        if (n == 1 || remain == 1) return remain;
        if (mem[n][remain]) return mem[n][remain];
        
        int ans = 0;
        for (int i = remain; i >= 1; --i)
            ans += dp(n - 1, i, mem);
        return mem[n][remain] = ans;
    };
};
