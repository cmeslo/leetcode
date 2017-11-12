class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        vector<int> cnt(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            cnt[nums[i] - 1]++;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (cnt[i] == 2) res[0] = i + 1;
            if (cnt[i] == 0) res[1] = i + 1;
            if (res[0] != 0 && res[1] != 0) return res;
        }
        return res;
    }
};
