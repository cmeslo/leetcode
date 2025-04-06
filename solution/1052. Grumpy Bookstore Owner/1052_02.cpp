class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int presum = 0, add_satisfied = 0, max_add_satisfied = 0;
        for (int i = 0; i < customers.size(); ++i) {
            presum += customers[i] * !grumpy[i];
            add_satisfied += customers[i] * grumpy[i];
            if (i >= minutes)
                add_satisfied -= customers[i - minutes] * grumpy[i - minutes];
            max_add_satisfied = max(max_add_satisfied, add_satisfied);
        }
        return presum + max_add_satisfied;
    }
};

// 1 [0 1 2] 1 1 7 5
//        i
    
// 1 0 1 2 1  1 7 5
// 0 1 0 1 0 [1 0 1]
