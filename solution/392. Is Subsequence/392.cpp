class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        
        int s_idx = 0, t_idx = 0;
        while (t_idx < t.size()) {
            if (s[s_idx] == t[t_idx]) s_idx++;
            if (s_idx >= s.size()) return true;
            t_idx++;
        }
        return false;
    }
};
