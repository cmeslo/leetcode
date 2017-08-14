class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;

        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; ++i)
        {    
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {    
                int left = j + 1, right = nums.size() - 1;
                
                while (left < right) {
                    //std::cout << nums[i] << ", " << nums[j] << ", " << nums[left] << ", " << nums[right] << std::endl;
                    
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (nums[right] == nums[right - 1]) right--;
                        left++, right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j + 1]) j++;
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1]) i++;
        }
        //std::cout << "==========" << std::endl;
        return ans;
    }
};

int main() {
    Solution* sol = new Solution;
    //vector<int> test = {1, 0, -1, 0, -2, 2}; // target = 0
    //vector<int> test = {0, 0, 0, 0}; // target = 0
    vector<int> test = {-1, 0, 1, 2, -1, -4}; // target = -1;
    //vector<int> test = {-3, -1, 0, 2, 4, 5}; // target = 2
    vector<vector<int>> ans = sol->fourSum(test, -1);
    
    for (auto i : ans) {
        for (auto j : i) {
            std::cout << j << ", ";
        }
        std::cout << std::endl;
    }
}