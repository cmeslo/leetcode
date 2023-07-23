class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i <= (int)haystack.size() - (int)needle.size(); ++i) {
            for (int j = 0; j < needle.size() && haystack[i + j] == needle[j]; ++j) {
                if (j == needle.size() - 1) return i;
            }
        }
        return -1;
    }
};
