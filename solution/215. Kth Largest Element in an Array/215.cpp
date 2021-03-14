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
