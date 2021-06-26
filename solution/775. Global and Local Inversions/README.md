# 775. Global and Local Inversions

## Solution 1

### 解釋

```
[x x x x x] i x x
```

記錄在 [0, i-1] 範圍內的最大值 mx，一旦 mx > nums[i + 1] 就會出現至少一個 global inversions.

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
