class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> res(k + 1);
        
        res[0] = 1;
        for (int i = k; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                res[j] += res[j-1];
            }
        }
        
        return res;
    }
};
