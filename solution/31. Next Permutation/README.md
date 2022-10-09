# 31. Next Permutation #

## 31.cpp ##

![31_Next_Permutation](https://github.com/cmeslo/leetcode/blob/master/solution/31.%20Next%20Permutation/31_Next_Permutation.gif)

[source](https://leetcode.com/articles/next-permutation/)


```cpp
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 1;;

    for (i = n - 1; i > 0; --i) {
        if (nums[i - 1] < nums[i]) {
            for (int j = n - 1; j >= i; --j) {
                if (nums[i - 1] < nums[j]) {
                    swap(nums[i - 1], nums[j]);
                    break;
                }
            }
            break;
        }
    }

    reverse(begin(nums) + i, end(nums));
}
```

or

```cpp
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 1;
    while (i > 0 && nums[i - 1] >= nums[i]) {
        --i;
    }
    if (i != 0) {
        int j = i;
        while (j < n && nums[i - 1] < nums[j]) {
            ++j;
        }
        swap(nums[i - 1], nums[j - 1]);
    }
    sort(nums.begin() + i, nums.end());
}
```
