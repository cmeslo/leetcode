class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<int> zeros;
        
        for (const auto& row : grid) {
            int zero_cnt = 0;
            for (int i = n-1; i >= 0 && row[i] == 0; i--)
                ++zero_cnt;
            zeros.push_back(zero_cnt);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            int z = n - i - 1; // the i-th row needs n-i-1 zeros
            
            // find the first row with at least z tailing zeros
            while (j < n && zeros[j] < z) ++j;
            if (j == n) return -1;
            
            while (j > i) {
                swap(zeros[j], zeros[j-1]);
                --j;
                ++ans;
            }
        }
        
        return ans;
    }
};
