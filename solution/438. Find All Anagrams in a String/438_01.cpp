class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.empty() || p.size() > s.size()) return vector<int>();

        vector<int> res;
        vector<int> cnt(26, 0); //a-z
        for (char c : p) cnt[c - 'a']++;
        
        for (int i = 0; i <= s.size() - p.size(); ++i) {
            int test = 1;
            vector<int> tmp = vector<int>(cnt);
            for (int j = i; j < i + p.size(); ++j) {
                int letter = s[j] - 'a';
                if (--tmp[letter] < 0) {
                    test = 0;
                    break;
                }
            }
            if (test == 1) res.push_back(i);
        }
        return res;
    }
};
