class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6;
        
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (sum_division(nums, mid) <= threshold)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
    
private:
    int sum_division(const vector<int>& nums, int d) {
        int sum = 0;
        for (int n : nums)
            sum += (n + (d - 1)) / d;
        return sum;
    }
};
