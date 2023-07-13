# 72. Edit Distance

## Solution 1

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(), l2 = word2.size();
        _d = vector<vector<int>>(l1+1, vector<int>(l2+1, -1));
        return minDist(word1, word2, l1, l2);
    }
private:
    vector<vector<int>> _d;
    int minDist(const string& word1, const string& word2, int l1, int l2) {
        if (word1 == word2) return 0;
        
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;
        
        if (_d[l1][l2] >= 0) return _d[l1][l2];
        
        int ans = 0;
        if (word1[l1-1] == word2[l2-1]) {
             ans = minDist(word1, word2, l1-1, l2-1);
        } else {
            ans = 1 + min(
                min(minDist(word1, word2, l1, l2-1), // insert
                    minDist(word1, word2, l1-1, l2)), // remove
                minDist(word1, word2, l1-1, l2-1) //replace
            );
        }
        return _d[l1][l2] = ans;
    }
};
```
