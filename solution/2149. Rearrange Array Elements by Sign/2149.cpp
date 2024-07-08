class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> P, N;
        for (int x : nums) {
            if (x > 0)
                P.push(x);
            else
                N.push(x);
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2) {
                res.push_back(N.front());
                N.pop();
            } else {
                res.push_back(P.front());
                P.pop();
            }
        }
        return res;
    }
};
