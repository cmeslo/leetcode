class Solution {
public:
    int countArrangement(int n) {
        vector<bool> used(n + 1);
        return dfs(n, n, used);
    }
    
private:
    int dfs(int n, int pos, vector<bool>& used) {
        if (pos <= 0) return 1;
        
        int ans = 0;
        for (int i = n; i >= 1; --i) {
            if (used[i]) continue;
            if (!(pos % i == 0 || i % pos == 0)) continue;
            used[i] = true;
            ans += dfs(n, pos - 1, used);
            used[i] = false;
        }
        return ans;
    }
};
