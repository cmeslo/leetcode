class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        
        vector<int> A;
        A.push_back(-1);
        for (int i = 0; i < n; ++i)
            if (nums[i] & 1)
                A.push_back(i);
        A.push_back(n);
        
        int res = 0;
        for (int i = 1; i < A.size() - 1; ++i) {
            if (i >= k)
                res += (A[i-k+1] - A[i-k]) * (A[i+1] - A[i]);
        }
        return res;
    }
};


// [1 1 2 1] 2
// [1 1 2 1  2]


// 1 {2 2 2 [1 2 1] 2 2 2} 1
