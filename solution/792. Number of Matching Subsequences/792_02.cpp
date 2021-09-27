class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(128);
        for (int i = 0; i < s.size(); ++i)
            pos[s[i]].push_back(i);
        
        int ans = 0;
        for (const string& word : words)
            if (isMatch(pos, word))
                ++ans;
        
        return ans;
    }
    
private:
    bool isMatch(vector<vector<int>>& pos, const string& word) {
        int i = 0;
        for (const char& c : word) {
            auto it = std::lower_bound(pos[c].begin(), pos[c].end(), i);
            if (it == pos[c].end()) return false;
            i = *it + 1;
        }
        return true;
    }
};
