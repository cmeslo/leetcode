# 154. Find Minimum in Rotated Sorted Array II

觀察一下會出現的可能性，就會發現用 mid 和 right 判斷會更容易處理

```
case 1:
      *
   *
*

case 2:
*       
      *
   *

case 3:
   *
*
     *

case 4:  
   *  *
*

or


*   *  *  * 不知道向哪一邊靠攏比較好，直接 right--
  *

case 5:
*       
   *  *
```

```cpp
int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right])
            right = mid;
        else if (nums[mid] > nums[right])
            left = mid + 1;
        else
            right--;

    }
    return nums[left];
}
```
