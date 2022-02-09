class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int max_group_size = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int group_size = 0, j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = nums[j];
                    ++group_size;
                }
                max_group_size = max(max_group_size, group_size);
            }
        }
        return max_group_size;
    }
};
