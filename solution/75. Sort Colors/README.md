# 75. Sort Colors

## Solution 1: Counter

```cpp
void sortColors(vector<int>& nums) {
    vector<int> color(3, 0);

    for (int n : nums)
        color[n]++;

    int idx = 0;
    for (int i = 0; i < 3; i++) {
        while (color[i]-- > 0)
            nums[idx++] = i;
    }
}
```

## Solution 2: Two Pointers

```cpp
void sortColors(vector<int>& nums) {
    int l = 0, m = 0, r = nums.size() - 1;
    while (m <= r) {
        if (nums[m] == 0)
            swap(nums[l++], nums[m++]);
        else if (nums[m] == 2)
            swap(nums[r--], nums[m]);
        else
            ++m;
    }
}
```

or

```cpp
void sortColors(vector<int>& nums) {
    int red = 0, blue = nums.size()-1;
    
    for (int i = 0; i <= blue; i++) {
        if (nums[i] == 0) {
            swap(nums[i], nums[red++]);
        } else if (nums[i] == 2) {
            swap(nums[i--], nums[blue--]);
        }
    }
}
```
