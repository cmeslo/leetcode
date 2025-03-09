class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i]) % k;
            if (m.count(sum)) {
                if (i - m[sum] > 1)
                    return true;
            } else {
                m[sum] = i;
            }
        }
        return false;
    }
};



// x x x [x x x x] x x
//     j        i

// (presum[i] - presum[j]) % k = 0

// presum[i] - presum[j] = n * k
// presum[j] = presum[i] - n * k
// presum[j] % k = presum[i] % k

// 23 2  4  6  6
// 23 25 29 35 41
