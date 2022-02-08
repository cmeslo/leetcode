class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        return nums[left];
    }
};

//      x
//    x
// [x]      <--應該 r = m

//   x
// x
//    [x]   <--應該 l = m + 1
      
// x
//     x
//  [x]     <--應該 r = m
 
// x 
//  [x]     <--應該 l = m + 1
