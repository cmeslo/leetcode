class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        
        for (int n : nums) {
            int i = abs(n) - 1;
            if (nums[i] < 0)
                res[0] = abs(n);
            else
                nums[i] *= -1;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                res[1] = i + 1;
                break;
            }
        }
        return res;
    }
};
