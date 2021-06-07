# 923. 3Sum With Multiplicity

## Solution 1 - O(n^2)

```cpp
// Your runtime beats 14.62 % of cpp submissions.

int threeSumMulti(vector<int>& arr, int target) {
    const int mod = 1e9 + 7;
    int n = arr.size();
    int ans = 0;
    unordered_map<int, int> m;

    for (int i = 1; i < n; ++i) {
        if (m.count(target - arr[i]))
            ans = (ans + m[target - arr[i]]) % mod;

        for (int j = i - 1; j >= 0; --j)
            ++m[arr[i] + arr[j]];
    }

    return ans;
}
```

or

```cpp
int threeSumMulti(vector<int>& arr, int target) {
    unordered_map<int, int> m;

    long ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            int t = target - arr[i] - arr[j];
            if (m.count(t)) ans += m[t];
        }
        ++m[arr[i]];
    }
    return ans % 1000000007;
}
```
