class Solution {
public:

/*
   sumi = n1*k + a
   sumj = n2*k + a
   sumi - sumj = (n1 - n2)*k
   subarray (i, j] contains a desired sum
*/

    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m{{0, -1}};
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (k != 0) sum %= k; // (n*k + a)%k  is same as  a%k
            if (m.count(sum)) {
                if (i - m[sum] > 1) return true;
            } else {
                m[sum] = i;
            }
        }
        return false;
    }
};
