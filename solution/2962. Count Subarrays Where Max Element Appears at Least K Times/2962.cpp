class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        
        vector<int> nextMax(n, n);
        int mx_idx = n;
        for (int i = n - 1; i >= 0; --i) {
            nextMax[i] = mx_idx;
            if (nums[i] == mx)
                mx_idx = i;
        }
        
        long long res = 0;
        int mx_cnt = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            if (nums[j] == mx && ++mx_cnt == k) {
                while (mx_cnt == k) {
                    if (nums[i] == mx) {
                        res += 1L * (i + 1) * (nextMax[j] - j);
                        mx_cnt--;
                    }
                    i++;
                }
            }
        }
        return res;
    }
};


// . . x . . [x . . x] . . .
//            i     j        n

           
// 1 [3 2 3] 3
// 0  1 2 3  4
