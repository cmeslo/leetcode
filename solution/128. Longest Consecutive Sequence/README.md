# 128. Longest Consecutive Sequence

## Solution 1: set

因為題目要求 ```O(n)``` time，

所以用個取巧一點的方法 - set，來取代 sort。

```cpp
int longestConsecutive(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();

    set<int> s;
    for (int x : nums) s.insert(x);

    int ans = 1, cnt = 1;
    auto it = s.begin(); ++it;
    for (; it != s.end(); ++it) {
        if (*prev(it) + 1 == *it) ++cnt;
        else cnt = 1;
        ans = max(ans, cnt);
    }
    return ans;
}
```

## Solution 2: unordered_set

把所有數字放到 set 裡，同時只由每組 consecutive sequence 裡的第一個數字開始處理。

```cpp
// Your runtime beats 12.00 % of cpp submissions.

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s(begin(nums), end(nums));
    int ans = 0;
    for (int x : nums) {
        if (s.count(x - 1)) continue;
        int cnt = 0;
        while (s.count(x++)) ++cnt;
        ans = max(ans, cnt);
    }
    return ans;
}
```
