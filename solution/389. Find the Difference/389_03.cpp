class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> letters(26, 0);
        
        for (int i = 0; i < s.length(); ++i)
            ++letters[s[i] - 'a'];
        
        for (int i = 0; i < t.length(); ++i)
            --letters[t[i] - 'a'];
        
        for (int i = 0; i < letters.size(); ++i)
            if (letters[i] != 0) return i + 'a';
        
        return '\0';
    }
};
