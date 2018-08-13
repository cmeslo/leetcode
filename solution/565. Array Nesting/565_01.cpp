class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxS = 0;
        vector<bool> visited(nums.size(), false);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;
            int a = i, currS = 1;
            while (nums[a] != i) {
                visited[a] = true;
                currS++;
                a = nums[a];
            }
            if (currS > maxS) maxS = currS;
        }
        
        return maxS;
    }
};
