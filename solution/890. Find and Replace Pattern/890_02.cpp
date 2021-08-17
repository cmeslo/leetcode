class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string p = normalize(pattern);
        for (string& w : words) if (normalize(w) == p) ans.push_back(w);
        return ans;
    }
    
private:
    string normalize(string s) {
        unordered_map<char, int> m;
        for (char& c : s) if (m.find(c) == m.end()) m[c] = m.size();
        for (int i = 0; i < s.size(); ++i) s[i] = 'a' + m[s[i]];
        return s;
    }
};
