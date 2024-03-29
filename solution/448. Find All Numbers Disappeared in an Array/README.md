# Find All Numbers Disappeared in an Array

## 448_01.cpp
由於使用了```sort```排序，可以通過，但達不到O(N).

## 448_02.cpp
用 ```nums[i]``` 與 ```nums[nums[i] - 1]```替換的方法

## 448_03.cpp
第一個循環，用負數作標記，表示對應位置通過：
```
[4,3,2,7,8,2,3,1]
[o,o,o,o,x,x,o,o]
```

第二個循環，把沒有通過的值(正數)取出：
```
[5,6]
```

### Code

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0)
            nums[index] = -nums[index];
    }
    vector<int> res;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0)
            res.push_back(i + 1);
    }
    return res;
}
```
