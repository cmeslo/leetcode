# 350. Intersection of Two Arrays II

## Solution: Hashmap

```cpp
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    vector<int> f1(1001), f2(1001);
    for (int x : nums1) ++f1[x];
    for (int x : nums2) ++f2[x];

    for (int i = 0; i <= 1000; ++i) {
        while (f1[i]-- && f2[i]--)
            ans.push_back(i);
    }
    return ans;
}
```
