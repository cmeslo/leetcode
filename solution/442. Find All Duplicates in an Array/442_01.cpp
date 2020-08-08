class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for (int i = 0; i < nums.size(); ++i) {
            int j = abs(nums[i]) - 1;
            if (nums[j] < 0) res.push_back(j + 1);
            nums[j] = -nums[j];
        }
        
        return res;
    }
};
