class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0, presum = 0;
        for (int x : nums) {
            presum += x;
            if (m.count(presum - goal))
                res += m[presum - goal];
            m[presum]++;
        }
        return res;
    }
};
