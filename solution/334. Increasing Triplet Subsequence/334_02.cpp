class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        
        for (int n : nums) {
            if (n <= m1)
                m1 = n;
            else if (n <= m2)
                m2 = n;
            else
                return true;
        }
        
        return false;
    }
};
