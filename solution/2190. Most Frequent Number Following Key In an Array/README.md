# 2190. Most Frequent Number Following Key In an Array

```cpp
int mostFrequent(vector<int>& nums, int key) {
    unordered_map<int, int> m;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] == key)
            m[nums[i]]++;
    }
    int ans = 0, cnt = 0;
    for (auto [k, c] : m)
        if (c > cnt) {
            ans = k;
            cnt = c;
        }
    return ans;
}
```
