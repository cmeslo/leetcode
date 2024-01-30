class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> res;
        string cur;
        dfs(digits, 0, cur, res);
        return res;
    }

private:
    const vector<string> m = {
        "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void dfs(const string& digits, int i, string& cur, vector<string>& res) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        for (const char& c : m[digits[i] - '0']) {
            cur.push_back(c);
            dfs(digits, i + 1, cur, res);
            cur.pop_back();
        }
    }
};
