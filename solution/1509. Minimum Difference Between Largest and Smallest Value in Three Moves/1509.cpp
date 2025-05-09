class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        if (n <= 4) return 0;
        
        return min({
            nums[n - 4] - nums[0],
            nums[n - 1] - nums[3],
            nums[n - 2] - nums[2],
            nums[n - 3] - nums[1]
        });
    }
};

// 2 3 4 5
// 3 3 3 3
// 4 4 4 4

//  0 1  5 10 14
// [0 1] 1  1  1


//  0  1  2  3  4  5  6
//  x  .  .  x [.  .  .]
// [.  .  .] x  .  .  x
// [.  .] x  .  .  x [.]
// [.] x  .  .  x [.  .]
