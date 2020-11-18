class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> glasses(query_row + 1);
        
        glasses[0] = poured;
        for (int i = 0; i < query_row; ++i) {
            for (int j = i; j >= 0; --j) {
                glasses[j + 1] += glasses[j] = max(0.0, (glasses[j] - 1) / 2.0);
            }
        }
        
        return min(1.0, glasses[query_glass]);
    }
};
