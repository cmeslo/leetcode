#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int ans = nums[0], productMax = nums[0], productMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                swap(productMax, productMin);
            }
            productMax = max(productMax * nums[i], nums[i]);
            productMin = min(productMin * nums[i], nums[i]);

            ans = max(productMax, ans);
        }
        return ans;
    }
};

void main()
{
    auto ans = new Solution;

//    vector<int> test = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    vector<int> test = { 2, 3, -2, 4 };
    cout << ans->maxProduct(test) << endl;
    
}
