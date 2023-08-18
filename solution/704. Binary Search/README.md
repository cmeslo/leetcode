# 704. Binary Search

左閉右開， ```l = mid + 1```, ```r = mid```, 最終 ```l``` 和 ```r``` 重疊，不用糾結選 ```l``` 還是 ```r```.

```cpp
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid;
    }

    return -1;
}
```

or

```cpp
int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size(), m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (nums[m] < target)
            l = m + 1;
        else
            r = m;
    }
    return l < nums.size() && nums[l] == target ? l : -1;
}
```
