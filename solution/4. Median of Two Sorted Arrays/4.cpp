class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size(), y = nums2.size();
        if (x > y)
            return findMedianSortedArrays(nums2, nums1);
        
        int odd = (x + y) % 2;
        
        int left = 0, right = x;
        while (left <= right) {
            int partitionX = left + (right - left) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;
            
            int leftMaxX = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];
            int rightMinX = partitionX == x ? INT_MAX : nums1[partitionX];
            
            int leftMaxY = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];
            int rightMinY = partitionY == y ? INT_MAX : nums2[partitionY];
            
            if (leftMaxX <= rightMinY && leftMaxY <= rightMinX) {
                if (odd)
                    return max(leftMaxX, leftMaxY);
                else
                    return (double) (max(leftMaxX, leftMaxY) + min(rightMinX, rightMinY)) / 2;
            } else if (leftMaxX > rightMinY) {
                right = partitionX - 1;
            } else {
                left = partitionX + 1;
            }
        }
        return -1;
    }
};
