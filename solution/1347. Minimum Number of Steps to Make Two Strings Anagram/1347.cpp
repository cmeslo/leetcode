class Solution {
public:
    int minSteps(string s, string t) {
        int res = 0;
        vector<int> f(26);
        for (int i = 0; i < s.size(); ++i) {
            ++f[s[i] - 'a'];
            --f[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i)
            if (f[i] > 0)
                res += f[i];
        return res;
    }
};

// a b
// 1 2
    
// a b
// 2 1
