class Solution {
public:
    int minSwaps(vector<int>& nums) {
        return min(minSwaps(nums, 0), minSwaps(nums, 1));
    }
    
    int minSwaps(vector<int>& nums, int x) {
        int n = nums.size(), cnt = 0;
        vector<int> presum(n);
        if (nums[0] == x) {
            presum[0] = 1;
            cnt = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1];
            if (nums[i] == x) {
                cnt++;
                presum[i]++;
            }
        }
        if (cnt == 0) return 0;
        
        int res = n;
        for (int i = cnt - 1; i < n; ++i) {
            int left = i - cnt < 0 ? 0 : presum[i - cnt];
            int mid = presum[i] - left;
            res = min(res, cnt - mid);
        }
        return res;
    }
};


// x x [x x x] x x
// [x x x] x x x x
