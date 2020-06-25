class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        
        while (left < right) {
            mid = left + ((right-left)>>1);
            
            int cnt = 0;
            for (int n : nums) {
                if (n <= mid) cnt++;
            }
            
            if (cnt > mid)
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};
