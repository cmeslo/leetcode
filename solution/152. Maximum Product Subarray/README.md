# 152. Maximum Product Subarray

這類同時涉及正負號的問題，通常是要把循環過程中 <strong>最大</strong>、<strong>最小</strong> 兩個數同時記錄，

因為負負得正，有機會最小變最大、最大變最小

而遇到 0 時則會重置

## 152_01.cpp

```cpp
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
```

## 152_02.cpp 

```cpp
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int minP = nums[0], maxP = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        int mx = maxP, mi = minP;
        maxP = max(nums[i], max(nums[i] * mx, nums[i] * mi)); // max({nums[i], nums[i] * mx, nums[i] * mi});
        minP = min(nums[i], min(nums[i] * mx, nums[i] * mi)); // min({nums[i], nums[i] * mx, nums[i] * mi});
        ans = max(ans, maxP);
    }

    return ans;
}
```
