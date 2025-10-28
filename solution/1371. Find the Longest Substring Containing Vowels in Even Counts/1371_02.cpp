class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> m{{0, -1}};
        
        int res = 0;
        for (int i = 0, state = 0; i < s.size(); ++i) {
            
            int idx = string("aeiou").find(s[i]);
            if (idx != -1)
                state ^= (1 << idx);
            
            if (m.count(state))
                res = max(res, i - m[state]);
            else
                m[state] = i;
        }
        return res;
    }
};
