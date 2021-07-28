class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0;
        int steps = 0;
        while (start <= end) {
            int end_next = end;
            for (int i = start; i <= end; ++i) {
                if (i == nums.size() - 1) return steps;
                end_next = max(end_next, i + nums[i]);
            }
            steps++;
            start = end + 1;
            end = end_next;
        }
        return -1;
    }
};
