class Solution {
public:
    int maxPower(string s) {
        char pre = ' ';
        int max_pow = 0, pow = 1;
        
        for (const char& c : s) {
            pow = pre == c ? pow + 1 : 1;
            max_pow = max(max_pow, pow);
            pre = c;
        }
        
        return max_pow;
    }
};
