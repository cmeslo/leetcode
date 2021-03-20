# 1673. Find the Most Competitive Subsequence

## 解釋

用新數字取代舊數字的條件：

1. 新數字比較 Competitive (比舊數字小)
2. 確保 當前答案的 size - 1 後，剩餘數字```(n - i)```，仍然足夠去組成 k 個數

```
size - 1 + n - i >= k
```

## Code

### 寫法一：用 stack

```cpp
vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();
    stack<int> q;

    for (int i = 0; i < n; ++i) {
        while (!q.empty() && q.size() - 1 + n - i >= k && q.top() > nums[i])
            q.pop();
        if (q.size() < k)
            q.push(nums[i]);
    }

    vector<int> ans(k);
    for (int i = k - 1; i >= 0; --i) {
        ans[i] = q.top();
        q.pop();
    }

    return ans;
}
```

### 寫法二：把 vector 當 stack 用

```cpp
vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        while (!ans.empty() && ans.size() - 1 + n - i >= k && ans.back() > nums[i])
            ans.pop_back();
        if (ans.size() < k)
            ans.push_back(nums[i]);
    }

    return ans;
}
```

### 寫法三：用 index

```cpp
vector<int> mostCompetitive(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans(k);
    int size = 0;

    for (int i = 0; i < nums.size(); ++i) {
        while (size && ans[size - 1] > nums[i] && size - 1 + n - i >= k)
            --size;

        if (size < k)
            ans[size++] = nums[i];
    }

    return ans;
}
```
