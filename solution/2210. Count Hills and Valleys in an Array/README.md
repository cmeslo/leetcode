# 2210. Count Hills and Valleys in an Array

```cpp
int countHillValley(vector<int>& nums) {
    vector<int> A;
    A.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] == nums[i]) continue;
        A.push_back(nums[i]);
    }
    
    int res = 0;
    for (int i = 1; i < A.size() - 1; ++i) {
        if ((A[i - 1] < A[i] and A[i] > A[i + 1])
           or (A[i - 1] > A[i] and A[i] < A[i + 1]))
            ++res;
    }
    return res;
}
```

or

```cpp
int countHillValley(vector<int>& nums) {
    int res = 0;
    for (int i = 0, j = 1; j < nums.size() - 1; ++j) {
        if ((nums[i] < nums[j] && nums[j] > nums[j + 1]) ||
            (nums[i] > nums[j] && nums[j] < nums[j + 1])) {
               ++res;
               i = j;
           }
    }
    return res;
}
```
