class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int x : nums)
            m[x]++;
        
        int size = m[nums[0]];
        for (auto [x, cnt] : m)
            if (cnt % 2 != 0)
                return false;
        return true;
    }
};
