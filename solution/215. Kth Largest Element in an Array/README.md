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

# Solution 3: partition (題目想要的解法)

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
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        --k;
        while (l < r) {
            int pivotPos = partition(nums, l, r);
            if (pivotPos == k) return nums[k];
            l = pivotPos < k ? pivotPos + 1 : l;
            r = pivotPos < k ? r : pivotPos - 1;
        }
        return nums[k];
    }
    
private:
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
