# 442. Find All Duplicates in an Array

## 442_01.cpp
每遇到一個數字，就把該數字對應的下標的值取負數，遇到負數代表該下標已經出現過一次。

```
原數組內容：
[ 4, 3, 2, 7, 8, 2, 3, 1]

val = 4
[ 4, 3, 2,-7, 8, 2, 3, 1]

val = 3
[ 4, 3,-2,-7, 8, 2, 3, 1]

val = 2
[ 4,-3,-2,-7, 8, 2, 3, 1]

val = 7
[ 4,-3,-2,-7, 8, 2,-3, 1]

val = 8
[ 4,-3,-2,-7, 8, 2,-3,-1]

val = 2
[ 4,-3,-2,-7, 8, 2,-3,-1] -> find 2

val = 3
[ 4,-3,-2,-7, 8, 2,-3,-1] -> find 3

val = 1
[-4,-3,-2,-7, 8, 2,-3,-1]
```

```cpp
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
            ans.push_back(index + 1);
        else
            nums[index] = -nums[index];
    }
    return ans;
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

or

```cpp
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] != 0 && nums[i] != i + 1) {
            if (nums[i] == nums[nums[i] - 1]) {
                ans.push_back(nums[i]);
                nums[i] = 0;
                break;
            }
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    return ans;
}

// 0 1 2 3 4 5 6 7
// 1 2 3 4 x x 7 8
// 4 3 2 7 8 2 3 1

// [7]3 2 4 8 2 3 1
// [3]3 2 4 8 2 7 1
// [2]3 3 4 8 2 7 1
// [0]2 3 4 8 2 7 1 --> find 3
//  0 2 3 4[1]2 7 8
//  1 2 3 4[0]2 7 8
//  1 2 3 4 0[2]7 8 --> find 2
//  1 2 3 4 0 0 7 8
```
