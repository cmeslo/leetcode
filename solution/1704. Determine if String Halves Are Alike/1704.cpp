class Solution {
public:
    bool halvesAreAlike(string s) {
        const int n = s.size();
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int cnt = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (vowels.count(s[i])) ++cnt;
            if (vowels.count(s[i + n/2])) --cnt;
        }
        return cnt == 0;
    }
};
