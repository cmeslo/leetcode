class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            
            unordered_set<int> s;
            for (int n : nums) {
                s.insert(n & mask); // reserve Left bits and ignore Right bits
            }
            
            int tmp = max | (1 << i); // in each iteration, there are pair(s) whoes Left bits can XOR to max
            for (int prefix : s) {
                if (s.find(prefix ^ tmp) != s.end()) {
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};
