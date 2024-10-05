class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    int atMost(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            if (m[nums[j]]++ == 0) --k;
            while (k < 0) {
                if (--m[nums[i++]] == 0) ++k;
            }
            res += j - i + 1;
        }
        return res;
    }
};
