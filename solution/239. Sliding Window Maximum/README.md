# 239. Sliding Window Maximum

## Brute force (TLE)

Time complexity: O((n - k + 1) * k)

```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    for (int i = k - 1; i < nums.size(); ++i) {
        ans.push_back(*max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
    }
    return ans;
}
```

## Monotonic Queue with value (239_01.cpp)

Time complexity: O(n)

```cpp
// 568 ms
// Your runtime beats 30.13 % of cpp submissions.

class MonotonicQueue {
private:
    deque<int> _data;

public:
    void push(int e) {
        while (!_data.empty() && _data.back() < e) _data.pop_back();
        _data.push_back(e);
    }
    
    void pop() {
        _data.pop_front();
    }
    
    int max() {
        return _data.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            q.push(nums[i]);
            if (i - k + 1 >= 0) {
                ans.push_back(q.max());
                if (nums[i - k + 1] == q.max()) q.pop();
            }
        }
        
        return ans;
    }
};
```

## Monotonic Queue with index (239_02.cpp)

Monotonic Queue 保存 index，省去重複值的麻煩，也較簡潔。

Time complexity: O(n)

```cpp
// 364 ms
// Your runtime beats 77.30 % of cpp submissions.

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> indexs;

    for (int i = 0; i < nums.size(); ++i) {
        while (!indexs.empty() && nums[indexs.back()] <= nums[i])
            indexs.pop_back();
        indexs.push_back(i);

        if (i < k - 1) continue;

        ans.push_back(nums[indexs.front()]);

        if (i - k + 1 == indexs.front())
            indexs.pop_front();
    }

    return ans;
}
```

## Split windows (239_03.cpp)

分割窗口、做兩遍掃瞄，左往右、右往左、分別保存最大值，速度最快。

Time complexity: O(n)

```cpp
// 344ms
// Your runtime beats 92.63 % of cpp submissions.

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> max_left(n), max_right(n);

    max_left[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        max_left[i] = i % k ? max(max_left[i - 1], nums[i]) : nums[i];
    }

    max_right[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        max_right[i] = i % k ? max(nums[i], max_right[i + 1]) : nums[i];
    }

    vector<int> ans(n - k + 1);
    for (int i = 0; i + k - 1 < n; ++i) {
        ans[i] = max(max_left[i + k - 1], max_right[i]);
    }

    return ans;
}
```
