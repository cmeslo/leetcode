# 2200. Find All K-Distant Indices in an Array

```cpp
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size();
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == key)
            A.push_back(i);
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(A.begin(), A.end(), i);
        if (it != A.end() && abs(*it - i) <= k)
            ans.push_back(i);
        else if (it != A.begin() && abs(i - *prev(it)) <= k)
            ans.push_back(i);
    }
    return ans;
}
```
