class Solution {
public:
    int majorityElement(vector<int>& nums) { // using Moore Voting Algorithm
        int res = 0, cnt = 0;
        for (int x : nums) {
            if (cnt == 0) {
                res = x;
                cnt++;
            } else {
                res == x ? cnt++ : cnt--;
            }            
        }
        return res;
    }
};
