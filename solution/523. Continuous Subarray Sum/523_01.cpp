class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int x = sum % k;
            if (x == 0 && i > 0) return true;
            if (m.count(x) && i - m[x] >= 2) return true;
            if (!m.count(x)) m[x] = i;
        }
        return false;
    }
};

// x x x [x x x] x x
//        i   j

// sum[i:j] % k = 0

// (sum[j] - sum[i-1]) % k = 0;

// sum[j] - x = nk;

// sum[j] - nk = x

// sum[j] % k = x % k
