# 1234. Replace the Substring for Balanced String

## Solution: Two Pointers

要用 ```O(1)``` 時間去判斷、移除當前窗口內的元素後，整個 string 是否 balanced。

```cpp
class Solution {
public:
    int balancedString(string s) {
        n = s.size();
        for (char& c : s) ++count[c];
        
        unordered_map<char, int> sum;
        if (isOK(sum)) return 0;
        
        int ans = n;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < n && !isOK(sum)) {
                sum[s[j]]++;
                ++j;
            }
            if (isOK(sum))
                ans = min(ans, j - i);
            sum[s[i]]--;
        }
        return ans;
    }

private:
    unordered_map<char, int> count;
    int n;
    
    bool isOK(unordered_map<char, int>& sum) {
        for (auto [c, val] : count) {
            if (val - sum[c] > n/4)
                return false;
        }
        return true;
    }
};
```

or

```cpp
int balancedString(string s) {
    int n = s.size(), k = n / 4;
    int res = n, i = 0;

    unordered_map<int, int> count;
    for (char& c : s)
        ++count[c];

    for (int j = 0; j < n; ++j) {
        count[s[j]]--;
        while (i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
            res = min(res, j - i + 1);
            count[s[i++]]++;
        }
    }
    return res;
}
```
