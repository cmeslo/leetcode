# 260. Single Number III

## Solution

先利用 XOR 去得到 a ^ b，再利用 XOR 的特性，1 ^ 0 = 1，

找到 a ^ b 裡其中一個 1 bit ，去把整個數組分割成兩部分，

第一部分全部 XOR 放入 res[0]，另一部分全部 XOR 放入 res[1]。


```cpp
vector<int> singleNumber(vector<int>& nums) {
    long ab = 0;
    for (int x : nums)
        ab ^= x;

    int lastBit = ab & (-ab);

    vector<int> res = {0, 0};
    for (int x : nums) {
        if (x & lastBit)
            res[0] ^= x;
        else
            res[1] ^= x;
    }
    return res;
}
```
