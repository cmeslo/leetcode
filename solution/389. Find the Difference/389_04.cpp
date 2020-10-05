class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> letters(26, 0);
        
        for (int i = 0; i < s.length(); ++i) {
            ++letters[s[i] - 'a'];
            --letters[t[i] - 'a'];
        }
        --letters[t.back() - 'a'];
        
        for (int i = 0; i < letters.size(); ++i)
            if (letters[i] != 0) return i + 'a';
        
        return '\0';
    }
};
