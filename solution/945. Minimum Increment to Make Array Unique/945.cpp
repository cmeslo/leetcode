class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int res = 0, need = 0;
        for (int x : nums) {
            res += max(need - x, 0);
            need = max(need, x) + 1;
        }
        return res;
    }
};

// 1 1 2 2 3 7
// 1 2 3 4

// 1 2 3 4 5 7
