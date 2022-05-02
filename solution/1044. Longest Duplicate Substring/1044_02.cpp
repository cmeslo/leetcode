class Solution {
public:
    string longestDupSubstring(string s) {
        startPos = -1;
        
        int n = s.size();
        vector<uint64_t> p(n);
        p[0] = 1;
        p[1] = 31;
        for (int i = 2; i < n; ++i)
            p[i] = p[i - 1] * p[1];
        
        int l = 0, r = n - 1;
        while (l < r) {
            int m = r - (r - l) / 2;
            if (checkOK(s, m, p))
                l = m;
            else
                r = m - 1;
        }
        return startPos == -1 ? "" : s.substr(startPos, l);
    }
    
private:
    int startPos;
    
    bool checkOK(string& s, int len, vector<uint64_t>& p) {
        if (len <= 0) return false;
        unordered_set<uint64_t> seen;
        
        uint64_t hash = 0;
        for (int i = 0; i < s.size(); ++i) {
            hash = hash * p[1] + s[i] - 'a';
            if (i >= len - 1) {
                if (seen.count(hash)) {
                    startPos = i - len + 1;
                    return true;
                }
                seen.insert(hash);
                hash -= (s[i - len + 1] - 'a') * p[len - 1];
            }
        }
        return false;
    }
};
