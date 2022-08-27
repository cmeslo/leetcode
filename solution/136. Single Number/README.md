# 136. Single Number

## Solution: XOR

```cpp
int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int x : nums)
        res ^= x;
    return res;
}
```
