class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(begin(nums), end(nums), -x);
        
        if (target < 0) return -1;
        if (target == 0) return n;
        
        int len = INT_MIN;
        int sum = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            sum += nums[j];
            
            while (sum > target) // 因為target > 0，所以必定有解，i 不會超過 j，可以不用檢查 i <= j
                sum -= nums[i++];
            
            if (sum == target)
                len = max(len, j - i + 1);
        }
        
        return len == INT_MIN ? -1 : n - len;
    }
};
