# 18. 4Sum

```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    const int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    for (int a = 0; a < n; ++a) {
        if (a && nums[a - 1] == nums[a]) continue; // 確保在第一個位置上的數字只會出現一次
        for (int b = a + 1; b < n; ++b) {
            if (b > a + 1 && nums[b - 1] == nums[b]) continue; // 確保在第二個位置上的數字只會出現一次
            int c = b + 1, d = n - 1;
            while (c < d) {
                long sum = (long)nums[a] + nums[b] + nums[c] + nums[d];
                if (sum < target)
                    ++c;
                else if (sum > target)
                    --d;
                else {
                    ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                    while (c < d && nums[c] == nums[c + 1]) ++c; // 確保在第三個位置上的數字只會出現一次
                    while (c < d && nums[d] == nums[d - 1]) --d; // 確保在第四個位置上的數字只會出現一次
                    ++c, --d;
                }
            }
        }
    }
    return ans;
}
```
