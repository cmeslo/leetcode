class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> f(26);
        for (char& c : s)
            f[c - 'a']++;
        for (char& c : t)
            if (--f[c - 'a'] < 0)
                return c;
        return '0';
    }
};