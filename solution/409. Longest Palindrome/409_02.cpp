class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> odds;
        for (char c : s) {
            if (!odds.count(c)) odds.insert(c);
            else odds.erase(c);
        }
        return s.size() - max(0, (int)odds.size() - 1);
    }
};
