#include <iostream>
#include <climits>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        int diff = abs(res - target);
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right) {
                //std::cout << nums[i] << ", " << nums[left] << ", " << nums[right] << std::endl;
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    if (sum == target) return sum;
                    res = sum;
                }
                sum > target? right-- : left++;
            } 
        }
        return res;
    }
};

int main() {
    Solution* sol = new Solution;
    //vector<int> test = {-1, 2, 1, -4}; // target = 1
    //vector<int> test = {0, 0, 0}; // target = 1
    //vector<int> test = {1, 1, -1, -1, 3}; // target = -1
    //vector<int> test = {1, 1, 1, 1}; // target = 0
    vector<int> test = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6}; // target = -59
    std::cout << sol->threeSumClosest(test, -59) << std::endl;
}