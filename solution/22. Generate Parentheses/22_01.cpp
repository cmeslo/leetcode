class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string out = "";
        dfs(n, 0, 0, out, res);
        return res;
    }
    
    void dfs(int n, int left, int right, string out, vector<string>& res) {
        if (left < n) {
            out.push_back('(');
            dfs(n, left + 1, right, out, res);
            out.pop_back();
        }
        if (left > right) {
            out.push_back(')');
            dfs(n, left, right + 1, out, res);
            out.pop_back();
        }
        if (left == n && right == n) {
            res.push_back(out);
        }
    }
};
