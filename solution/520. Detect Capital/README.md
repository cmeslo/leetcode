# 520. Detect Capital

```cpp
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
```

or

```cpp
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
```
