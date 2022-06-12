class Solution {
public:
    int rob(vector<int>& nums) {
        int prepre = 0, pre = 0;
        for (int x : nums) {
            int cur = max(prepre + x, pre);
            prepre = pre;
            pre = cur;
        }
        return max(prepre, pre);
    }
};
