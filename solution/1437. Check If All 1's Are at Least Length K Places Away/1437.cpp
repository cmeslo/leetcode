class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int zeros = k;
        for (int x : nums) {
            if (x) {
                if (zeros < k) return false;
                zeros = 0;
            } else {
                ++zeros;
            }
        }
        return true;
    }
};
