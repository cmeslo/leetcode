# 376. Wiggle Subsequence

## Solution 1 - Greedy

關鍵是找到所有轉折點，定義一個<code>方向變量</code>來判斷轉折點，

同時要考慮<strong>連續相等</strong>的情況，以及<code>方向變量</code>的初始化。

```cpp
int wiggleMaxLength(vector<int>& nums) {
    int ans = 1;
    int dir = 0;

    for (int i = 1; i < nums.size(); ++i) {
        int pre_dir = dir;

        if (nums[i - 1] < nums[i])
            dir = 1;
        else if (nums[i - 1] > nums[i])
            dir = -1;

        if (pre_dir != dir)
            ++ans;
    }

    return ans;
}
```

## Solution 2 - DP

拼接上一個轉折點，

down 後面接 up，

up 後面接 down。

```cpp
int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();

    int up = 1, down = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] > nums[i])
            up = down + 1;
        else if (nums[i - 1] < nums[i])
            down = up + 1;
    }

    return max(up, down);
}
```
