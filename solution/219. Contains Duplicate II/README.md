# 219. Contains Duplicate II

## Solution: Hash map

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> last;
    for (int i = 0; i < nums.size(); ++i) {
        if (last.count(nums[i]) && i - last[nums[i]] <= k)
            return true;
        last[nums[i]] = i;
    }
    return false;
}
```

## Solution: Sliding windows

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<int> s;
    int n = nums.size();
    if (n < 2) return false;
    for (int i = 0; i < n; ++i) {
        if (k < i) s.erase(nums[i - k - 1]);
        if (!s.insert(nums[i]).second) return true;
    }
    return false;
}
```
