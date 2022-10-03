class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int a : nums) {
            int x = abs(a);
            if (nums[x] < 0)
                return x;
            nums[x] *= -1;
        }
        return -1;
    }
};
