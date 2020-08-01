class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) return true;
        
        int i = 0;
        string rest = word.substr(i + 1);
        
        if ('A' <= word[i] && word[i] <= 'Z') {
            return isAllUpperCase(rest) || isAllLowerCase(rest);
        } else if ('a' <= word[i] && word[i] <= 'z') {
            return isAllLowerCase(rest);
        }
        
        return false;
    }
    
private:
    bool isAllUpperCase(const string& word) {
        for (const char& c : word)
            if (c < 'A' || c > 'Z') return false;
        return true;
    }
    
    bool isAllLowerCase(const string& word) {
        for (const char& c : word)
            if (c < 'a' || c > 'z') return false;
        return true;
    }
};
