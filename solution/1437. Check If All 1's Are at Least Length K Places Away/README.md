# 1437. Check If All 1's Are at Least Length K Places Away

## Solution 1：記錄上一次出現 1 的位置

```cpp
bool kLengthApart(vector<int>& nums, int k) {
    for (int pre = -1, i = 0; i < nums.size(); ++i) {
        if (!nums[i]) continue;
        if (pre >= 0 && i - pre - 1 < k)
            return false;
        pre = i;
    }
    return true;
}
```

## Solution 2：數一下兩個 1 之間有多少個 0

```cpp
bool kLengthApart(vector<int>& nums, int k) {
    int zeros = k;
    for (int x : nums) {
        if (x) {
            if (zeros < k) return false;
            zeros = 0;
        } else {
            ++zeros;
        }
    }
    return true;
}
```
