class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size() - 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            int leftCnt = 0;
            for (int n : nums) {
                if (n <= mid) ++leftCnt;
            }
            if (leftCnt <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
