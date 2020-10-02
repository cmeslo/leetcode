class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        int res1 = 0, res2 = 0, cnt1 = 0, cnt2 = 0;
        
        for (int n : nums) {
            if (res1 == n) cnt1++;
            else if (res2 == n) cnt2++;
            else if (cnt1 == 0) res1 = n, cnt1 = 1;
            else if (cnt2 == 0) res2 = n, cnt2 = 1;
            else cnt1--, cnt2--;
        }
        
        cnt1 = 0, cnt2 = 0;
        for (int n : nums) {
            if (n == res1) cnt1++;
            else if (n == res2) cnt2++;
        }

        if (cnt1 > nums.size() / 3) ans.push_back(res1);
	if (cnt2 > nums.size() / 3) ans.push_back(res2);
        return ans;
    }
};
