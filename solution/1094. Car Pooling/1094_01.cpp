class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> sums(1001, 0);
        for (auto& trip : trips) {
            for (int i = trip[1]; i < trip[2]; ++i) {
                sums[i] += trip[0];
                if (sums[i] > capacity) return false;
            }
        }
        
        return true;
    }
};
