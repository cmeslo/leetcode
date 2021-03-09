# 88. Merge Sorted Array

## 88.cpp

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    --m, --n;
    int index = nums1.size() - 1;

    while (m >= 0 && n >= 0) {
        if (nums1[m] < nums2[n])
            nums1[index--] = nums2[n--];
        else
            nums1[index--] = nums1[m--];
    }
    while (n >= 0)
        nums1[index--] = nums2[n--];
}
```

簡化一下：

```cpp
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos = (m--) + (n--) - 1;
    while (m >= 0 && n >= 0) {
        nums1[pos--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
    }
    while (n >= 0) {
        nums1[pos--] = nums2[n--];
    }
}
```
