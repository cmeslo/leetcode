# 169. Majority Element

## Solution 1: Hashmap

```cpp
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> m(nums.size());

    for (int x : nums) {
        m[x]++;
        if (m[x] > nums.size() / 2) return x;
    }
    return 0;
}
```

## Solution 2: Moore Voting Algorithm

```cpp
int majorityElement(vector<int>& nums) {
    int res = 0, cnt = 0;
    for (int x : nums) {
        if (cnt == 0) {
            res = x;
            cnt++;
        } else {
            res == x ? cnt++ : cnt--;
        }            
    }
    return res;
}
```
