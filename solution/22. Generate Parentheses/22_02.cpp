class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(n, n, n, "", res);
        return res;
    }
    
    void dfs(int n, int left, int right, string out, vector<string>& res) {
        if (left < 0 || right < 0 || right < left) return;
        
        if (left == 0 && right == 0) {
            res.push_back(out);
        }
        
        dfs(n, left - 1, right, out + "(", res);
        dfs(n, left, right - 1, out + ")", res);
    }
};
