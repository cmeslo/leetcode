# 775. Global and Local Inversions

## Solution 1

### 解釋

```
[x x x x x] i x x
```

記錄在 ```[0, i-1]``` 範圍內的最大值 ```mx```，一旦 ```mx > nums[i + 1]``` 就會出現至少一個 global inversions.

### Code

```cpp
bool isIdealPermutation(vector<int>& nums) {
    int mx = INT_MIN;
    for (int i = 1; i < nums.size(); ++i) {
        if (mx > nums[i]) return false;
        mx = max(mx, nums[i - 1]);
    }
    return true;
}
```

or

```cpp
bool isIdealPermutation(vector<int>& A) {
    int n = A.size();
    int mx = INT_MIN;
    for (int i = 0; i < n - 2; ++i) {
        mx = max(mx, A[i]);
        if (mx > A[i + 2]) return false;
    }
    return true;
}
```

## Solution 2

### 解釋

題目還有一個條件：```all the integers in the range [0, n - 1]```

如果 local inversions 要等於 global inversions，

那麼每個值```nums[i]```與它的下標 ```i``` 的差值（距離）就不能超過 1 了.

### Code

```cpp
bool isIdealPermutation(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i)
        if (abs(A[i] - i) > 1) return false;
    return true;
}
```
