class Solution {
public:
    Solution(vector<int>& nums) {
        A_ = nums;
    }
    
    vector<int> reset() {
        return A_;
    }
    
    vector<int> shuffle() {
        int n = A_.size();
        vector<int> res = A_;
        for (int i = 0; i < n; ++i) {
            int j = rand() % (n - i) + i;
            swap(res[i], res[j]);
        }
        return res;
    }
    
private:
    vector<int> A_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
