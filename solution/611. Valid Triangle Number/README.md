# 611. Valid Triangle Number

## Solution 1

```cpp
// Your runtime beats 11.88 % of cpp submissions.
// Your memory usage beats 91.36 % of cpp submissions.

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto it = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
            int k = it - nums.begin() - 1;
            if (nums[i] + nums[j] > nums[k])
                ans += k - j;
        }
    }

    return ans;
}
```

## Solution 2: Two pointers (推薦)

```cpp
// Your runtime beats 94.84 % of cpp submissions.
// Your memory usage beats 99.82 % of cpp submissions.

int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int k = n - 1; k >= 2; --k) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                ans += j - i;
                j--;
            } else {
                i++;
            }
        }
    }
    return ans;
}
```
