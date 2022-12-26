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
