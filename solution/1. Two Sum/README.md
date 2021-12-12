# 1. Two Sum

## Solution 1: Brute force

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (nums[i] + nums[j] == target)
                return {i, j};

    return {};
}
```

## Solution 2: Hashmap

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
        if (m.count(target - nums[i]))
            return {m[target - nums[i]], i};
        m[nums[i]] = i;
    }
    return {-1, -1};
}
```
