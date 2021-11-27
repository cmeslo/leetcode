class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int pos = 0;
        int left_mx = nums[0], mx = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            mx = max(mx, nums[i]);
            if (left_mx > nums[i]) {
                pos = i;
                left_mx = mx;
            }
        }
        return pos + 1;
    }
};
