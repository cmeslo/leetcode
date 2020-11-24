class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        
        for (int i = 1; i < n; ++i) {
            len[i] = cnt[i] = 1;
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
        }
        
        int ans = 0;
        int max_len = *max_element(len.begin(), len.end());
        for (int i = 0; i < n; ++i)
            if (len[i] == max_len)
                ans += cnt[i];
        
        return ans;
    }
};
