# 567. Permutation in String

## Solution: Sliding window

```cpp
// Runtime: 6 ms, Your runtime beats 89.70 % of cpp submissions.

bool checkInclusion(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 > len2) return false;

    vector<int> m(26);
    int count = 0;
    for (char& c : s1)
        m[c - 'a']++;

    for (int i = 0; i < len2; ++i) {
        if (m[s2[i] - 'a']-- > 0)
            ++count;
        if (i >= len1 && ++m[s2[i - len1] - 'a'] > 0)
            --count;
        if (count == len1)
            return true;
    }
    return false;
}
```

or

```cpp
// Runtime: 12 ms, Your runtime beats 64.86 % of cpp submissions.

class Solution {
private:
    bool isAllZero(vector<int> &count) {
        for (int c : count) {
            if (c != 0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        
        vector<int> count(26, 0);
        for (int i = 0; i < m; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isAllZero(count)) return true;
        for (int i = m; i < n; ++i) {
            count[s2[i] - 'a']--;
            count[s2[i-m] - 'a']++;
            if (isAllZero(count)) return true;
        }
        return false;
    }
};
```
