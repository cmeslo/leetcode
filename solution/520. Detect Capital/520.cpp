class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char& c : word) {
            if ('A' <= c && c <= 'Z')
                ++count;
        }
        return (count == word.size())
            || (count == 0)
            || (count == 1 && 'A' <= word[0] && word[0] <= 'Z');
    }
};
