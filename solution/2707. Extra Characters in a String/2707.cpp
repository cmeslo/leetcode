class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        memo.resize((int)s.size(), -1);
        return dfs(s, 0, dict);
    }

private:
    vector<int> memo;

    int dfs(const string& s, int start, unordered_set<string>& dict) {
        if (start == s.size()) return 0;
        if (memo[start] != -1) return memo[start];

        string cur = "";
        int res = s.size();
        for (int i = start; i < s.size(); ++i) {
            cur.push_back(s[i]);
            int left = dict.count(cur) ? 0 : cur.size();
            int right = dfs(s, i + 1, dict);
            res = min(res, left + right);
        }
        return memo[start] = res;
    }
};
