class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> f(26);
        for (char& c : p)
            f[c - 'a']++;
        
        vector<int> res;
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= p.size()) {
                if (++f[s[i - p.size()] - 'a'] > 0)
                    count--;
            }
            if (f[s[i] - 'a']-- > 0) {
                if (++count == p.size())
                    res.push_back(i - p.size() + 1);
            }
        }
        return res;
    }
};
