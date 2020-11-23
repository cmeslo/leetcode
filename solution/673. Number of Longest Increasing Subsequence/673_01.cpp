class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_len = 1, res = 0;
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        
        for (int i = 0; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            
            if (max_len < len[i]) {
                max_len = len[i];
                res = cnt[i];
            } else if (max_len == len[i]) {
                res += cnt[i];
            }
        }
        
        return res;
    }
};
