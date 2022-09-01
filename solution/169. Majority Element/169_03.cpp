class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int x : nums) {
                if ((x >> i) & 1)
                    ++cnt;
            }
            ans |= cnt > nums.size() / 2 ? (1 << i) : 0;
        }
        return ans;
    }
};


// x x x x x b b


// 0 0 0 1 0
// 0 0 0 1 0
// 0 0 0 1 0
// 0 0 0 1 0
// 0 1 0 0 1

// 0 1 1
// 0 1 0
// 0 1 1
