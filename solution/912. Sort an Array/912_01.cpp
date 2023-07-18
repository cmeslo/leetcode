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
