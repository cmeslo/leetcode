class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) return true;
        
        string rest = word.substr(1);
        return isupper(word[0]) ? isAllUpper(rest) || isAllLower(rest) : isAllLower(rest);
    }
    
private:
    bool isAllUpper(const string& word) {
        for (const char& c : word)
            if (!isupper(c)) return false;
        return true;
    }
    
    bool isAllLower(const string& word) {
        for (const char& c : word)
            if (!islower(c)) return false;
        return true;
    }
};
