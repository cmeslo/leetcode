class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] == nums[m + 1]) {
                if (m % 2)
                    r = m - 1;
                else
                    l = m + 2;
            } else {
                if ((m + 1) % 2)
                    r = m;
                else
                    l = m + 1;
            }
        }
        return nums[l];
    }
};

// x x x x x [3] 3 x x x x

// x x x x x 3 [3] x x x x

// [1] 2
