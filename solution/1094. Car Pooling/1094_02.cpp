class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> d(1001, 0);
        
        for (auto& trip : trips) {
            d[trip[1]] += trip[0];
            d[trip[2]] -= trip[0];
        }
        
        int sum = 0;
        for (int c : d) {
            sum += c;
            if (sum > capacity) return false;
        }
        
        return true;
    }
};
