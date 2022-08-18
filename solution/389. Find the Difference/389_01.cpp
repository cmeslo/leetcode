class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (char c : s) ans ^= (c - 'a');
        for (char c : t) ans ^= (c - 'a');
        return ans + 'a';

    }
};
