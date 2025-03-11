class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0, sum = 0;
        for (int x : nums) {
            sum = (sum + x % k + k) % k;
            res += m[sum];
            m[sum]++;
        }
        return res;
    }
};


// x x [x x x] x x x
//   j      i

// presum[i] - presum[j] = n * k
// presum[j] = presum[i] - n * k
// presum[j] % k = presum[i] % k

// 7  4  -10
// 7 11  1
