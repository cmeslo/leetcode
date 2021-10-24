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

## Solution 2: Deque

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

## Solution 3: Binary search (推薦)

以上解法都要 ```O(n)```，但這個解法只要 ```O(log(N-K) + K)```，

用 binary search 去尋找 window 的左邊界，

注意這裡是用 ```arr[left]``` 和 ```arr[left + k]``` 作比較，

而且判斷時不可以取絶對值，原因可以看[詳細解釋](https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K))。

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int low = 0, high = arr.size() - k;
    while (low < high) {
        int left = low + (high - low) / 2;
        if (x - arr[left] <= arr[left + k] - x)
            high = left;
        else
            low = left + 1;
    }
    return vector<int>(arr.begin() + low, arr.begin() + low + k);
}
```
