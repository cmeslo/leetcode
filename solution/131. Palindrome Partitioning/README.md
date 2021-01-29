# 131. Palindrome Partitioning

```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> cur;
        vector<vector<string>> ans;
        dfs(s, 0, cur, ans);
        return ans;
    }
    
private:
    void dfs(const string& s, int start, vector<string>& cur, vector<vector<string>>& ans) {
        if (start == s.length()) {
            ans.push_back(cur);
            return;
        }
        
        for (int i = start; i < s.length(); ++i) {
            if (isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                dfs(s, i + 1, cur, ans);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
```
