class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        presum_.resize(n + 1);
        for (int i = 0; i < n; ++i)
            presum_[i + 1] = presum_[i] + nums[i];
    }
    
    int sumRange(int left, int right) {
        return presum_[right + 1] - presum_[left];
    }
    
private:
    vector<int> presum_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
