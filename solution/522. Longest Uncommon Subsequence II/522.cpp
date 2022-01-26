class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), [&](const string& a, const string& b) {
            return a.size() > b.size();
        });
        
        for (int i = 0; i < n; ++i) {
            bool is_uncommon = true;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    is_uncommon = false;
                    break;
                }
            }
            if (is_uncommon) return strs[i].size();
        }
        return -1;
    }
    
private:
    bool isSubsequence(const string& a, const string& b) {
        if (a.size() > b.size()) return false;
        int i = 0;
        for (int j = 0; i < a.size() && j < b.size(); ++j)
            if (a[i] == b[j]) ++i;
        return i == a.size();
    }
};
