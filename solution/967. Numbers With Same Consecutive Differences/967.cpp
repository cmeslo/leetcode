class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        if (N == 1) ans.push_back(0);
        for (int i = 1; i < 10; i++) {
            dfs(N - 1, K, i, ans);
        }
        return ans;
    }
    
private:
    void dfs(int n, int k, int cur, vector<int>& ans) {
        if (n == 0) {
            ans.push_back(cur);
            return;
        }
        
        if (k == 0) {
            dfs(n - 1, k, cur*10 + cur%10, ans);
        } else {
            if (cur%10 - k >= 0) dfs(n - 1, k, cur*10 + (cur%10 - k), ans);
            if (cur%10 + k <= 9) dfs(n - 1, k, cur*10 + (cur%10 + k), ans);
        }
        
    }
};
