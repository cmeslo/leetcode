class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mx_cnt = 0;
        long long res = 0;
        
        for (int i = 0, j = 0; j < n; ++j) {
            if (nums[j] == mx) {
                ++mx_cnt;
                while (mx_cnt >= k) {
                    res += n - j;
                    if (nums[i++] == mx)
                        --mx_cnt;
                }
            }
        }
        return res;
    }
};


// [. . x . . x . . x] . . .
//  i               j        n
 
// . [. x . . x . . x] . . .
//    i             j        n

           
// 1 [3 2 3] 3
// 0  1 2 3  4
