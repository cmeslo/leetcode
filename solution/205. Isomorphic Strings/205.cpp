class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        vector<int> m1(128, -1), m2(128, -1);
        for (int i = 0; i < n; ++i) {
            if (m1[s[i]] != m2[t[i]]) return false;
            m1[s[i]] = i;
            m2[t[i]] = i;
        }
        return true;
    }
};
