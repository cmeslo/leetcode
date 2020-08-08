# 442. Find All Duplicates in an Array

## 442_01.cpp
每遇到一個數字，就把該數字對應的下標的值取負數，遇到負數代表該下標已經出現過一次。

```
原數組內容：
[ 4, 3, 2, 7, 8, 2, 3, 1]

4
[ 4, 3, 2, 7, 8, 2,-3, 1]

3:
[ 4,-3, 2, 7, 8, 2, 3, 1]

2
[ 4,-3,-2, 7, 8, 2, 3, 1]

7
[ 4,-3, 2, 7, 8, 2, 3, 1] --->找到2

8
[-4,-3, 2, 7, 8, 2, 3, 1]

2
[-4,-3,-2, 7, 8, 2, 3, 1] 

3
[-4, 3,-2, 7, 8, 2, 3, 1] --->找到3

1
[-4, 3,-2,-7, 8, 2, 3, 1]
```

```cpp
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;

    for (int i = 0; i < nums.size(); ++i) {
        int j = abs(nums[i]) - 1;
        if (nums[j] < 0) res.push_back(j + 1);
        nums[j] = -nums[j];
    }

    return res;
}
```

## 442_02.cpp

```cpp
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == i+1) continue;
        while (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i+1) ans.push_back(nums[i]);
    }

    return ans;
}
```
