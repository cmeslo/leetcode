class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string_view> dict(wordDict.begin(), wordDict.end());
        unordered_map<string_view, bool> memo;
        return dfs(s, 0, dict, memo);
    }
    
private:
    bool dfs(const string_view& s, int len, unordered_set<string_view>& dict, unordered_map<string_view, bool>& memo) {
        if (dict.find(s) != dict.end()) return memo[s] = true;
        if (memo.find(s) != memo.end()) return memo[s];
        
        for (int i = len + 1; i < s.length(); ++i) {
            const string_view& left = s.substr(0, i);
            const string_view& right = s.substr(i);
            if (dict.count(right) && dfs(left, 0, dict, memo))
                return memo[s] = true;
        }
        
        return memo[s] = false;
    }
};
