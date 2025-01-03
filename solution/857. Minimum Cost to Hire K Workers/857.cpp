class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        const int n = quality.size();
        vector<pair<int, int>> P;
        for (int i = 0; i < n; ++i)
            P.push_back({quality[i], wage[i]});
        
        sort(P.begin(), P.end(), [](auto& a, auto& b) {
            return a.second * 1.0 / a.first < b.second * 1.0 / b.first;
        });
        
        priority_queue<int> pq;
        int quality_sum = 0;
        double res = 1e20;
        for (auto& [q, w] : P) {
            double unitWage = w * 1.0 / q;
            quality_sum += q;
            if (pq.size() > k - 1) {
                quality_sum -= pq.top();
                pq.pop();
            }
            pq.push(q);
            
            if (pq.size() == k)
                res = min(res, unitWage * quality_sum);
        }
        return res;
    }
};



// wageEarn[i] / quality[i] = unitWage

// wageEarn[i] => wage[i]
// wageEarn[i] / quality[i] => wage[i] / quality[i]
// unitWage => wage[i] / quality[i]

// unitWageExp_1, unitWageExp_2, ..., unitWageExp_t, ... unitWageExp_t+1, unitWageExp_t+2

// res = wageEarn[1] + uniteWage[2] + ... + uniteWage[k]
//     = unitWage*quality[1] + unitWage*quality[2] + unitWage*quality[3]
//     = uniteWage * quality_sum
