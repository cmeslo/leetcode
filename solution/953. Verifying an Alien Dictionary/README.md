# 953. Verifying an Alien Dictionary

```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26);
        for (int i = 0; i < 26; ++i)
            dict[order[i] - 'a'] = i;
        
        for (int i = 1; i < words.size(); ++i) {
            if (checkGreater(words[i - 1], words[i], dict))
                return false;
        }
        return true;
    }
private:
    bool checkGreater(string& A, string& B, const vector<int>& dict) {
        int len = min(A.size(), B.size());
        for (int i = 0; i < len; ++i) {
            const char& a = dict[A[i] - 'a'], b = dict[B[i] - 'a'];
            if (a > b) return true;
            if (a < b) return false;
        }
        return A.size() > B.size();
    }
};
```
