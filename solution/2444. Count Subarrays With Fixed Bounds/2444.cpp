class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int preMin = -1, preMax = -1, boundary = -1;
        
        long long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || maxK < nums[i]) {
                boundary = i;
            }
            if (nums[i] == minK) {
                preMin = i;
            }
            if (nums[i] == maxK) {
                preMax = i;
            }
            res += max(0, min(preMin, preMax) - boundary);
        }
        return res;
    }
};

// o .. x x [x x x x x x i]
// ^         ^     ^
// boundary  minK  maxK
