# 2216. Minimum Deletions to Make Array Beautiful

```cpp
int minDeletion(vector<int>& nums) {
    int n = nums.size();
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        if ((A.size() % 2 == 0) || (A.size() % 2 == 1 && A.back() != x)) {
            A.push_back(x);
        }
    }
    if (A.size() % 2 == 1) A.pop_back();
    return nums.size() - A.size();
}
```
