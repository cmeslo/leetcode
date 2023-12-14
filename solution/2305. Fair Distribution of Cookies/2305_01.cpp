class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> children(k);
        dfs(cookies, 0, children, ans);
        return ans;
    }
    
private:
    void dfs(vector<int>& cookies, int i, vector<int>& children, int& ans) {
        if (i == cookies.size()) {
            ans = min(ans, *max_element(children.begin(), children.end()));
            return;
        }
        
        for (int& child : children) {
            child += cookies[i];
            dfs(cookies, i + 1, children, ans);
            child -= cookies[i];
        }
    }
};
