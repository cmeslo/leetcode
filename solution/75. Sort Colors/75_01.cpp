class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> color(3, 0);
        
        for (int n : nums)
            color[n]++;
        
        int idx = 0;
        for (int i = 0; i < 3; i++) {
            while (color[i]-- > 0)
                nums[idx++] = i;
        }
    }
};
