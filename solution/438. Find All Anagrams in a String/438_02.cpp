class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty()) return {};
        vector<int> res;
        vector<int> m1(26, 0), m2(26, 0);
        for (int i = 0; i < p.size(); ++i) {
            m1[s[i] - 'a']++;
            m2[p[i] - 'a']++;
        }
        if (m1 == m2) res.push_back(0);
        
        for (int i = p.size(); i < s.size(); ++i) {
            --m1[s[i - p.size()] - 'a'];
            ++m1[s[i] - 'a'];
            if (m1 == m2) res.push_back(i - p.size() + 1);
        }
        
        return res;
    }
};
