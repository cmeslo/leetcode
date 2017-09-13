class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = 1 << nums.size();// we have 2^n subsets
        vector<vector<int>> res;
        
        for (int i = 0; i < len; ++i) {
            res.push_back(convertIntToSet(nums, i));
        }
        return res;
    }
    
    vector<int> convertIntToSet(vector<int>& nums, int subInt) {
        vector<int> sub;
        int index = 0;
        for (int i = subInt; i > 0; i >>= 1) {
            if (i & 1 == 1) sub.push_back(nums[index]);
            ++index;
        }
        return sub;
    }
};
