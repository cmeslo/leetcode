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
