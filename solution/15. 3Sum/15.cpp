#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        
        std::sort(nums.begin(), nums.end());
        
        for (int k = 0; k < nums.size() - 2; ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k-1]) continue; // remove duplicate
            int target = nums[k];
            int i = k + 1, j = nums.size() - 1;
            
            while (i < j) {
                int triple = nums[i] + nums[j] + target;
                //std::cout << nums[i] << ", " << nums[j] << ", " << nums[k] << std::endl;
                if (triple == 0) {
                    ans.push_back({target, nums[i], nums[j]});
                    while(nums[i] == nums[i + 1]) i++;
                	while(nums[j] == nums[j - 1]) j--;
                    i++; j--;
                } else if (triple < 0) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        //std::cout << "================" << std::endl;
        return ans;
    }
};

int main() {
    Solution* sol = new Solution;
    
    //vector<int> test = {-1, 0, 1, 2,-1 ,-4}; //-4, -1, -1, 0, 1, 2
    //vector<int> test = {0, 0, 0};
    vector<int> test = {-2, 0, 1, 1, 2};
    vector<vector<int>> ans = sol->threeSum(test);
    for (auto i : ans) {
        for (auto j : i) {
            std::cout << j << ", ";
        }
        std::cout<<endl;
    }
}