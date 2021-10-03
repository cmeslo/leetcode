# 15. 3Sum

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (i && nums[i - 1] == nums[i]) continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            if (nums[j] + nums[k] < - nums[i])
                ++j;
            else if (nums[j] + nums[k] > - nums[i])
                --k;
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                while (j < k && nums[j] == nums[j + 1]) ++j;
                while (j < k && nums[k - 1] == nums[k]) --k;
                ++j, --k;
            }
        }
    }
    return ans;
}
```
