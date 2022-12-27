# 665. Non-decreasing Array

## Solution 1

time: ```O(n)```

### 解釋：

當出現下降時，要考慮的點是：

```
x x x 6 3 x x x x
        ^-----要把它上升到 6

x x x 6 3 x x x x
      ^-----還是要把它下降到 3
```

### Code

```cpp
bool checkPossibility(vector<int>& nums) {
    int cnt = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > nums[i]) {
            if (i > 1 && nums[i - 2] > nums[i]) {
                nums[i] = nums[i - 1];
            } else {
                nums[i - 1] = nums[i];
            }
            if (++cnt > 1) return false;
        }
    }
    return true;
}
```

or

```cpp
bool checkPossibility(vector<int>& nums) {
    int mx = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) {
            if (mx > nums[i + 1])
                nums[i + 1] = nums[i];
            else
                nums[i] = mx;
            if (++cnt > 1) return false;
        }
        mx = max(mx, nums[i]);
    }
    return true;
}
```

## Solution 2: LIS

time: ```O(nlogn)```

```cpp
bool checkPossibility(vector<int>& nums) {
    vector<int> A;
    for (int x : nums) {
        if (A.empty() || A.back() <= x) {
            A.push_back(x);
        } else {
            auto it = upper_bound(A.begin(), A.end(), x);
            *it = x;
        }
    }
    return A.size() >= nums.size() - 1;
}
```
