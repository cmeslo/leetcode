# 456. 132 Pattern

## brute force

TLE超時的做法：

```cpp
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;

    for (int i = 0; i < n - 2; ++i)
        for (int j = i + 1; j < n - 1; ++j)
            for (int k = j + 1; k < n; ++k)
                if (nums[i] < nums[j] && nums[i] < nums[k] && nums[k] < nums[j])
                    return true;

    return false;
}
```

壓縮其中一層循環可以AC，但效率也不高：

```cpp
bool find132pattern(vector<int>& nums) {
    int n = nums.size();

    int numsi = INT_MAX;
    for (int j = 0; j < n - 1; ++j) {
        numsi = min(numsi, nums[j]);
        if (numsi == nums[j]) continue;
        for (int k = j + 1; k < n; ++k) {
            if (numsi < nums[k] && nums[k] < nums[j])
                return true;
        }
    }

    return false;
}
```

## 單調棧 (456_01.cpp)

```cpp
bool find132pattern(vector<int>& nums) {
    int n = nums.size();
    // if (n < 3) return false;

    vector<int> mins(n);
    mins[0] = nums[0];
    for (int i = 1; i < n; ++i)
        mins[i] = min(mins[i - 1], nums[i]); // 記錄所有數字，對應的 1

    stack<int> st;
    for (int j = n - 1; j >= 0; --j) {
        int nums_i = mins[j];
        while (!st.empty() && nums_i >= st.top()) // 以 1 作為短板、單調棧的篩選門檻，使棧內元素都比 1 大
            st.pop();

        if (!st.empty() && nums[j] > st.top()) // nums[j] 是 3，如果棧內元素比 3 小，就是找到 2 了
            return true;

        st.push(nums[j]);
    }

    return false;
}
```
