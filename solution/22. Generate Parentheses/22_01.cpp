class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        dfs(n, n, cur, res);
        return res;
    }
    
private:
    void dfs(int left, int right, string& cur, vector<string>& res) {
        if (right == 0) {
            res.push_back(cur);
            return;
        }
        if (left) {
            dfs(left - 1, right, cur += '(', res);
            cur.pop_back();
        }
        if (left < right) {
            dfs(left, right - 1, cur += ')', res);
            cur.pop_back();
        }
    }
};
