# 795. Number of Subarrays with Bounded Maximum

## Solution 1: Two pass（容易理解）

```小於等於 right 的集合``` 減去 ```小於 left 的集合```

```cpp
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums, right) - count(nums, left - 1);
    }
    
private:
    int count(vector<int>& nums, int N) {
        int res = 0, cur = 0;
        for (int x : nums) {
            if (x <= N)
                ++cur;
            else
                cur = 0;
            res += cur;
        }
        return res;
    }
};
```

## Solution 2: One pass

### Example
```
[1,1,2,1,1,4,2,3], L = 2, R = 3
left 用來記錄最後一個不符合的index，if (A[i] > R) left = i;
right 用來記錄最後一個符合的index，if (A[i] >= L) right = i;

i=0.    [1] 1 2 1 1 4 2 3
    l,r--------------------ans += r-l = (-1)-(-1) = 0

i=1.    1 [1] 2 1 1 4 2 3
    l,r--------------------ans += r-l = (-1)-(-1) = 0

i=2.    1 1 [2] 1 1 4 2 3
      l      r-------------ans += r-l = 2-(-1) = 3
                           包含了[1 1 2], [1, 2], [2]

i=3.    1 1 2 [1] 1 4 2 3
      l     r--------------ans += r-l = 2 - (-1) = 3
                           仔細看這裡，
                           它包含了[1 1 2 1], [1 2 1], [2, 1]，
                           相當於把 1 併接在了上一輪三個subarray的尾

i=4.    1 1 2 1 [1] 4 2 3
      l     r--------------ans += r-l = 2-(-1) = 3
                           它包含了[1 1 2 1 1], [1 2 1 1], [2 1 1]
                           相當於把 1 併接在了上一輪三個subarray的尾

i=5.    1 1 2 1 1 [4] 2 3
                  l,r----- ans += r-l = 5-5 = 0

i=6.    1 1 2 1 1 4 [2] 3
                  l  r-----ans += r-l = 6-5 = 1
                           它包含了[2]

i=7.    1 1 2 1 1 4 2 [3]
                  l    r---ans += r-l = 7-5 = 2
                           它包含了[2 3], [3]

ans = 12
```

### Code

```cpp
int numSubarrayBoundedMax(vector<int>& nums, int L, int R) {
    int ans = 0;
    int left = -1, right = -1;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > R) left = i;
        if (nums[i] >= L) right = i;
        ans += right - left;
    }
    return ans;
}
```

## Solution 3: Three pass, 單調棧

### Example
```
x 9 [x x 8 x x] 10 x x
  j      i      k

preGreaterOrEqual[i] = j
nextGreater[i] = k

ans += (i - j) * (k - i)

注意重複元素的計算：
x 9 x 8 [8 8 8] 10 x x
      j  i      k
```

### Code
```cpp
int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
    int n = nums.size();
    vector<int> preGreaterOrEqual(n, -1);
    vector<int> nextGreater(n, n);

    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            nextGreater[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && nums[i] >= nums[st.top()]) {
            preGreaterOrEqual[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (left <= nums[i] && nums[i] <= right) {
            int j =  preGreaterOrEqual[i], k = nextGreater[i];
            ans += (i - j) * (k - i);
        }
    }
    return ans;
}
```
