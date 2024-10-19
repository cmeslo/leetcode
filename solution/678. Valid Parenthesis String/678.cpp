class Solution {
public:
    bool checkValidString(string s) {
        int cMin = 0, cMax = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                cMin++;
                cMax++;
            } else if (s[i] == ')') {
                cMin--;
                cMax--;
            } else {
                cMax++;
                cMin--;
            }
            
            if (cMax < 0) return false; // 全部 * 當成左括號用都不夠
            if (cMin < 0) // 把太多 * 當成右括號用了, 要重置一下
                cMin = 0;
        }
        return cMin == 0;
    }
};
