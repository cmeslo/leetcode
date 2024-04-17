class Solution {
public:
    int maxScore(string s) {
        int res = -1, zeros = 0, ones = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') ++zeros;
            else ++ones;
            
            if (i != s.size() - 1)
                res = max(res, zeros - ones);
        }
        return res + ones;
    }
};

// res = max(zeroL + oneR)
//     = max(zeroL - oneL + oneL + oneR)
//     = max(zeroL - oneL) + oneTotal
