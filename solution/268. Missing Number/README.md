# 268. Missing Number

## Solution 1: Swap

### 寫法一 (268_01.cpp)

使用0去替代missing number，要注意0也可能是missing number.

```
3, 0, 1
1, 0, 3
```
答案：2

```
9, 6, 4, 2, 3, 5, 7, 0, 1
1, 2, 3, 4, 5, 6, 7, 0, 9
```
答案：8

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        while (nums[i] != 0 && nums[i] != i + 1) std::swap(nums[i], nums[nums[i] - 1]);
    }

    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) return i + 1;
    }

    return 0;
}
```

### 寫法二

```cpp
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != n && nums[i] != i)
            swap(nums[i], nums[nums[i]]);
    }
    for (int i = 0; i < n; ++i)
        if (nums[i] != i)
            return i;
    return n;
}
```

## 268_02.cpp
利用等差數列求和，計算出缺失的值
```
1/2 * n * (1 + n) - sum
```

```cpp
int missingNumber(vector<int>& nums) {
    int sum = 0, n = nums.size();

    for (auto &a : nums) {
        sum += a;
    }

    return 0.5 * n * (1 + n) - sum;
}
```

## 268_03.cpp
與原數本應該要出現的數字做XOR，讓出現過的數字消失
```
9,6,4,2,3,5,7,0,1
xor
1,2,3,4,5,6,7,8,9
```
得到答案8
