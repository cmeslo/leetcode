# 215. Kth Largest Element in an Array

# Solution 1: sorting

```cpp
int findKthLargest(vector<int>& nums, int k) {
    sort(begin(nums), end(nums), greater<int>());
    return nums[k - 1];
}
```

# Solution 2: heap

```cpp
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n : nums) {
        pq.push(n);
        if (pq.size() > k) pq.pop();
    }
    return pq.top();
}
```

# Solution 3: partition (推薦)

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quicksort(nums, 0, nums.size() - 1, k - 1);
        return nums[k - 1];
    }
    
private:
    void quicksort(vector<int>& nums, int l, int r, const int& k) {
        if (l >= r) return;
        int pivotPos = partition(nums, l, r);
        if (pivotPos == k) return;
        l = pivotPos < k ? pivotPos + 1 : l;
        r = pivotPos < k ? r : pivotPos - 1;
        quicksort(nums, l, r, k);
    }
    
    int partition(vector<int>& nums, int l, int r) {
        int pos = rand() % (r - l + 1) + l;
        int pivot = nums[pos];
        
        swap(nums[pos], nums[r]);
        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (nums[j] >= pivot)
                swap(nums[++i], nums[j]);
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
};
```

or

```cpp
// Runtime 15 ms, Beats 100%
// Memory 9.9 MB, Beats 100%

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        --k;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int pos = partition(nums, l, r);
            if (pos == k) return nums[k];
            if (pos < k)
                l = pos + 1;
            else
                r = pos - 1;
        }
        return nums[k];
    }
    
private:
    int partition(vector<int>& nums, int l, int r) {
        int rnd = rand() % (r - l + 1) + l;
        int pivot = nums[rnd];
        
        swap(nums[rnd], nums[r]);
        int i = l;
        for (int j = l; j < r; ++j) {
            if (nums[j] > pivot)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[r]);
        return i;
    }
};
```
