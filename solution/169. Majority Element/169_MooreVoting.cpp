class Solution {
public:
    int majorityElement(vector<int>& nums) { // using Moore Voting Algorithm
        int res = 0, cnt = 0;
        for (int n : nums) {
            if (cnt == 0) {
                res = n; cnt++;
            } else {
                res == n ? cnt++ : cnt--;
            }            
        }
        return res;
    }
};