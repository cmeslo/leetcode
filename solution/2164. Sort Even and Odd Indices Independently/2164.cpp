class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> A[2];
        for (int i = 0; i < nums.size(); ++i)
            A[i & 1].push_back(nums[i]);
        
        sort(A[0].begin(), A[0].end());
        sort(A[1].rbegin(), A[1].rend());
        
        for (int i = 0; i < nums.size(); ++i)
            nums[i] = A[i & 1][i / 2];
        return nums;
    }
};
