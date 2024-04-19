class Solution {
public:
    int maxScore(string s) {
        int res = 0, zeroL = 0, oneR = count(s.begin(), s.end(), '1');
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') ++zeroL;
            else --oneR;
            res = max(res, zeroL + oneR);
        }
        return res;
    }
};
