# 658. Find K Closest Elements

## Solution 1: Two Pointers

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    int i = 0;
    auto it = lower_bound(arr.begin(), arr.end(), x);
    if (it == arr.end())
        i = n - 1;
    else if (it != arr.begin() && x - *prev(it) <= *it - x)
        i = prev(it) - arr.begin();
    else
        i = it - arr.begin();

    int l = i, r = i;
    while (r - l + 1 < k) {
        if (l-1 >= 0 && r+1 < n) {
            if (x - arr[l-1] > arr[r+1] - x)
                r++;
            else
                l--;
        } else if (l-1 >= 0) {
            l--;
        } else if (r+1 < n) {
            r++;
        }
    }
    return vector<int>(arr.begin() + l, arr.begin() + r + 1);
}
```

## Solution 2: deque

用額外空間 - deque，去避免處理 index。

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    auto it = lower_bound(arr.begin(), arr.end(), x);
    int left = it - arr.begin() - 1;
    int right = it - arr.begin();

    deque<int> q;
    while (q.size() < k && left >= 0 && right < n) {
        if (x - arr[left] <= arr[right] - x)
            q.push_front(arr[left--]);
        else
            q.push_back(arr[right++]);
    }
    while (q.size() < k && left >= 0)
        q.push_front(arr[left--]);
    while (q.size() < k && right < n)
        q.push_back(arr[right++]);

    vector<int> ans;
    while (!q.empty()) {
        ans.push_back(q.front());
        q.pop_front();
    }
    return ans;
}
```

or

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int n = arr.size();
    auto it = lower_bound(arr.begin(), arr.end(), x);
    int i = it - arr.begin() - 1;
    int j = it - arr.begin();

    deque<int> q;
    while (q.size() != k) {
        if (i >= 0 && j < n) {
            if (x - arr[i] <= arr[j] - x)
                q.push_front(arr[i--]);
            else
                q.push_back(arr[j++]);
        } else if (i >= 0) {
            q.push_front(arr[i--]);
        } else if (j < n) {
            q.push_back(arr[j++]);
        }
    }

    vector<int> res;
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop_front();
    }
    return res;
}
```
