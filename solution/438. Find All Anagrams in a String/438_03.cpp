class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        
        vector<int> m(26, 0);
        for (char c : p) m[c - 'a']++;
        
        vector<int> res;
        int left = 0, right = 0, cnt = p.size();
        while (right < s.size()) {
            if (m[s[right++] - 'a']-- > 0) cnt--;
            if (cnt == 0) res.push_back(left);
            if (right - left == p.size() && m[s[left++] - 'a']++ >= 0) cnt++;
        }
        return res;
    }
};
