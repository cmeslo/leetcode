# 238. Product of Array Except Self

## 解釋

由於有 0 的存在，所以不能直接把整個數組的元素全部相乘，

於是採用左右遍歷的方法

```
x x x [x] x x x
---->     <----
```

## Code

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int product = 1;
    for (int i = 0; i < n; ++i) {
        res[i] = product;
        product *= nums[i];
    }
    product = 1;
    for (int i = n - 1; i >= 0; --i) {
        res[i] *= product;
        product *= nums[i];
    }
    return res;
}
```
