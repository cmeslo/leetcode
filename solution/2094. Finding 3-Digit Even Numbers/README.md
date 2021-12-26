# 2094. Finding 3-Digit Even Numbers

## Solution: Brute force

```cpp
vector<int> findEvenNumbers(vector<int>& digits) {
    set<int> s;
    int n = digits.size();
    for (int i = 0; i < n; ++i) {
        if (digits[i] == 0) continue;
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i == j || j == k || i == k) continue;
                if (digits[k] % 2) continue;
                s.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
            }
        }
    }
    return vector<int>(s.begin(), s.end());
}
```
