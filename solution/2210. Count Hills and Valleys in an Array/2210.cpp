class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> A;
        A.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) continue;
            A.push_back(nums[i]);
        }
        
        int res = 0;
        for (int i = 1; i < A.size() - 1; ++i) {
            if ((A[i - 1] < A[i] and A[i] > A[i + 1])
               or (A[i - 1] > A[i] and A[i] < A[i + 1]))
                ++res;
        }
        return res;
    }
};
