class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, sum = 0;
        for (int x : gain) {
            sum += x;
            res = max(res, sum);
        }
        return res;
    }
};
