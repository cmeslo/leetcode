# 16. 3Sum Closest

## Solution: Two pointers

```cpp
int threeSumClosest(vector<int>& nums, int target) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    int ans = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n; ++i) {
        if (i && nums[i - 1] == nums[i]) continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) return target;

            if (abs(target - sum) < abs(target - ans))
                ans = sum;

            if (sum < target)
                ++j;
            else if (sum > target)
                --k;
        }
    }
    return ans;
}
```
