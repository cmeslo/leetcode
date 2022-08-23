class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;
        
        vector<int> m(26);
        int count = 0;
        for (char& c : s1)
            m[c - 'a']++;
        
        for (int i = 0; i < len2; ++i) {
            if (m[s2[i] - 'a']-- > 0)
                ++count;
            if (i >= len1 && ++m[s2[i - len1] - 'a'] > 0)
                --count;
            if (count == len1)
                return true;
        }
        return false;
    }
};
