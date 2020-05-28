// Runtime: 4 ms
// Your runtime beats 98.88 % of cpp submissions.

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return vector<int>{0};
        vector<int> res {0};
        
        for (int i = 1; i <= num; i++) {
            if (i % 2 != 0) {
                res.push_back(res[i-1]+1);
            } else {
                res.push_back(res[i/2]);
            }
        }
        return res;
    }
};
