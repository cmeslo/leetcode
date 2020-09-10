# 220. Contains Duplicate III

以下兩種做法，為了做到 ```O(n logk)```，要限制 窗口/桶數目 的大小為 k

## 220_01.cpp

用 map 的 lower_bound 尋找 key 是 nums[i] - t 至 nums[i] + t 的鍵值對，

再配合滑動窗口

```cpp
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> window;

    for (int i = 0; i < nums.size(); ++i) {
        if (window.size() > k) window.erase(nums[i - k - 1]);

        auto it = window.lower_bound((long)nums[i] - t);
        if (it != window.end() && *it <= (long)nums[i] + t)
            return true;

        window.insert(nums[i]);
    }

    return false;
}
```

## 220_02.cpp

使用 bucket 的概念，注意每次檢查、要把前後桶都一併檢查

```cpp
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.empty() || k < 0 || t < 0) return false;

    int min_val = *min_element(begin(nums), end(nums));
    map<long, int> buckets;
    long bucket_width = (long)t + 1; // in case of zero

    for (int i = 0; i < nums.size(); ++i) {
        long bucket_index = ((long)nums[i] - min_val) / bucket_width;

        auto it = buckets.find(bucket_index - 1);
        if (it != buckets.end() && abs((long)nums[i] - it->second) < bucket_width)
            return true;

        it = buckets.find(bucket_index);
        if (it != buckets.end())
            return true;

        it = buckets.find(bucket_index + 1);
        if (it != buckets.end() && abs((long)nums[i] - it->second) < bucket_width)
            return true;

        buckets.insert({bucket_index, nums[i]});
        if (i >= k) buckets.erase(((long)nums[i - k] - min_val) / bucket_width);
    }

    return false;
}
```
