class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = haystack.find(needle);
        return i == string::npos ? -1 : i;
    }
};
