class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int sign = 1;
        long num = 0;
        
        while (i < n && s[i] == ' ') ++i;

        if (i < n && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '-' ? -1 : 1;
        
        for (; i < n && isdigit(s[i]); ++i) {
            num = num * 10 + (s[i] - '0');
            if (sign * num > INT_MAX) return INT_MAX;
            if (sign * num < INT_MIN) return INT_MIN;
        }
        return sign * num;
    }
};
