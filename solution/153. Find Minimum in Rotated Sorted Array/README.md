# 153. Find Minimum in Rotated Sorted Array

## 解釋

把最基本的情況列出，會發現只需要比較 mid 和 right

```
case 1:
     x
   x
[x]      <--應該 r = m

case 2:
  x
x
   [x]   <--應該 l = m + 1

case 3:
x
    x
 [x]     <--應該 r = m

case 4:
x 
 [x]     <--應該 l = m + 1
```

## Code

```cpp
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
```
