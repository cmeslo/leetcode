class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> count(n + 1);
        for (int x : nums) {
            if (x >= n)
                count[n]++;
            else
                count[x]++;
        }
        
        int cnt = 0;
        for (int i = n; i > 0; --i) {
            cnt += count[i];
            if (cnt == i)
                return i;
        }
        return -1;
    }
};
