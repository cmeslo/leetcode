class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        dfs(S, 0, ans);
        return ans;
    }
    
private:
    void dfs(string& s, int i, vector<string>& ans) {
        if (i >= s.size()) {
            ans.push_back(s);
            return;
        }
        
        dfs(s, i + 1, ans);
        if (isalpha(s[i])) {
            s[i] = s[i] ^ 32; // xor 32 (1 << 5) to toggle case
            dfs(s, i + 1, ans);
            s[i] = s[i] ^ 32;
        }
    }
};
