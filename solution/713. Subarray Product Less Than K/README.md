# 713. Subarray Product Less Than K

## Solution: Two Pointers

### 解釋

維護一個窗口，窗口內所有數的乘積小於K

ans += j - i + 1 是因為添加目前窗口內的答案時，一定要包含窗口內最後一個數字，比如：
```
(3, 4, 2), 窗口內有三個數字，答案只需要添加3個:

      (2)
   (4, 2)
(3, 4, 2)

(3, 4)的組合的答案在上一輪循環時已經包含了
```

### Code

```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int ans = 0;
    int i = 0, prod = 1;
    for (int j = 0; j < nums.size(); ++j) {
        prod *= nums[j];
        while (i <= j && prod >= k) {
            prod /= nums[i++];
        }
        ans += j - i + 1;
    }
    return ans;
}
```
