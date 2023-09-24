class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0, count = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i >= k && isVowel(s[i - k]))
                --count;
            if (isVowel(s[i]))
                ++count;
            res = max(res, count);
        }
        return res;
    }
    
    bool isVowel(char& c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
