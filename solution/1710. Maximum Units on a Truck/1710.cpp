class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes), end(boxTypes), [&](auto& a, auto& b) {
            return a[1] > b[1];
        });
        
        int ans = 0;
        for (int i = 0; i < boxTypes.size() && truckSize >= 0; ++i) {
            ans += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        return ans;
    }
};
