class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        const int n = customers.size();
        vector<int> presum1(n + 1), presum2(n + 1);
        presum1[1] = grumpy[0] == 0 ? customers[0] : 0;
        for (int i = 2; i <= n; ++i) {
            presum1[i] = presum1[i - 1] + (grumpy[i-1] == 0 ? customers[i-1] : 0);
        }
        
        presum2[1] = customers[0];
        for (int i = 2; i <= n; ++i) {
            presum2[i] = presum2[i - 1] + customers[i-1];
        }
        
        int res = presum1.back() - presum1[minutes] + presum2[minutes];
        for (int i = minutes + 1; i <= n; ++i) {
            int cnt_old = presum1[i] - presum1[i - minutes];
            int cnt_new = presum2[i] - presum2[i - minutes];
            res = max(res, presum1.back() - cnt_old + cnt_new);
        }
        return res;
    }
};

// 0 1 [0 1 2] 1 1 7 5
//          i
    
// 1 0 1 2 1  1 7 5
// 0 1 0 1 0 [1 0 1]
