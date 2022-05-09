class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long ab = 0;
        for (int x : nums)
            ab ^= x;
        
        int lastBit = ab & (-ab);
        
        vector<int> res = {0, 0};
        for (int x : nums) {
            if (x & lastBit)
                res[0] ^= x;
            else
                res[1] ^= x;
        }
        return res;
    }
};
