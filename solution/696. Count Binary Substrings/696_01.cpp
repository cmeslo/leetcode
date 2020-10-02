class Solution {
public:
    int countBinarySubstrings(string s) {
        if (s.empty()) return 1;
        
        int n = s.length();
        int zeros = 0, ones = 0;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                s[i] == '0' ? ++zeros : ++ones;
            } else {
                if (s[i] == '0') {
                    zeros = s[i - 1] == '0' ? zeros + 1 : 1;
                    if (ones >= zeros) ++ans;
                } else {
                    ones = s[i - 1] == '1' ? ones + 1 : 1;
                    if (zeros >= ones) ++ans;
                }
            }
        }
        
        return ans;
    }
};
