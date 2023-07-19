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
