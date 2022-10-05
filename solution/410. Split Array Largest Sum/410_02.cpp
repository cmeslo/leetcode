class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = 0, right = 0;
        for (int x : nums) {
            left = max(left, x);
            right += x;
        }
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (checkOK(nums, m, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    
private:
    bool checkOK(vector<int>& nums, int m, int limit) {
        int sum = 0;
        for (int x : nums) {
            sum += x;
            if (sum > limit) {
                if (--m <= 0) return false;
                sum = x;
            }
        }
        return true;
    }
};
