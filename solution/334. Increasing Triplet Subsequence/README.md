# 334. Increasing Triplet Subsequence

## 方法一

Time complexity: O(N)

Space complexity: O(N)

```cpp
bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    vector<int> mins(n), maxs(n);

    mins[0] = nums[0];
    for (int i = 1; i < n; ++i)
        mins[i] = min(mins[i - 1], nums[i]);

    maxs[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i)
        maxs[i] = max(nums[i], maxs[i + 1]);

    for (int i = 1; i < n - 1; ++i)
        if (mins[i] < nums[i] && nums[i] < maxs[i])
            return true;

    return false;
}
```

## 方法二

Time complexity: O(N)

Space complexity: O(1)


```
根據關係：i < j < k， nums[i] < nums[j] < nums[k]

可以設置2個變量: m1, m2

m1 代表最小值，m2 代表曾經比 m1 大的值

先設置 m1，再設置 m2，如果循環後面出現某個數字，大於 m2，代表找到一組 triple

即使 m1，之後被某個更小的數字更新了，也不會影響 m2 大於某一個數字的事實，比如

3, 4, 1, 5
^------------ m1 = 3
3, 4, 1, 5
   ^--------- m1 = 3, m2 = 4
3, 4, 1, 5
      ^------ m1 = 1, m2 = 4 (雖然1在4的後面，但m2依然比3大)
3, 4, 1, 5
         ^--- m1 = 1, m2 = 4 ，m2 < 5，找到符合的 triple
```

```cpp
bool increasingTriplet(vector<int>& nums) {
    int m1 = INT_MAX, m2 = INT_MAX;

    for (int n : nums) {
        if (n <= m1)
            m1 = n;
        else if (n <= m2)
            m2 = n;
        else
            return true;
    }

    return false;
}
```
