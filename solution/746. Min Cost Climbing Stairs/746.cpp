class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dpi = 0, dpi_1 = 0, dpi_2 = 0;
        
        for (int c : cost) {
            dpi = min(dpi_1, dpi_2) + c;
            dpi_2 = dpi_1;
            dpi_1 = dpi;
        }
        
        return min(dpi, dpi_2);
    }
};
