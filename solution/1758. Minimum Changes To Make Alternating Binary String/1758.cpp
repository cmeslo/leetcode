class Solution {
public:
    int minOperations(string s) {
        int res1 = 0, res2 = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i % 2 == 0) {
                res1 += s[i] != '0';
                res2 += s[i] != '1';
            } else {
                res1 += s[i] != '1';
                res2 += s[i] != '0';
            }
        }
        return min(res1, res2);
    }
};


// res1: 0101
// res2: 1010
