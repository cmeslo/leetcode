# 912. Sort an Array

## Solution 1: Quick Sort (TLE)

以前可以AC，現在會TLE

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pivotPos = partition(nums, l, r);
        quicksort(nums, l, pivotPos - 1);
        quicksort(nums, pivotPos + 1, r);
    }
    
    int partition(vector<int>& nums, int l, int r) {
        int pos = rand() % (r - l + 1) + l;
        int pivot = nums[pos];
        
        swap(nums[pos], nums[r]);
        int i = l;
        for (int j = l; j < r; ++j) {
            if (nums[j] <= pivot)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[r]);
        return i;
    }
};
```

## Solution 2: Merge Sort

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
    
private:
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        
        int m = l + (r - l) / 2;
        mergeSort(nums, l, m);
        mergeSort(nums, m + 1, r);
        
        int len = r - l + 1;
        vector<int> sorted(len);
        int i = l, j = m + 1;
        int k = 0;
        while (i <= m && j <= r) {
            sorted[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
        }
        while (i <= m) {
            sorted[k++] = nums[i++];
        }
        while (j <= r) {
            sorted[k++] = nums[j++];
        }
        for (int k = 0; k < len; ++k)
            nums[k + l] = sorted[k];
    }
};
```
