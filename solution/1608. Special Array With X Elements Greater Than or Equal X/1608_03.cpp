class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int n = nums.size();
        
        int l = 0, r = n, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            int cnt = 0;
            for (int x : nums)
                cnt += x >= m;
            
            if (cnt == m)
                return m;
            else if (cnt < m)
                r = m - 1;
            else if (cnt > m)
                l = m + 1;
        }
        return -1;
    }
};
