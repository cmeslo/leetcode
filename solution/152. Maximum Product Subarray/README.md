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
    int dp_max = nums[0], dp_min = nums[0];
    int res = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
        int mx = dp_max, mn = dp_min;
        if (nums[i] > 0) {
            dp_max = max(mx * nums[i], nums[i]);
            dp_min = min(mn * nums[i], nums[i]);
        } else if (nums[i] < 0) {
            dp_max = max(mn * nums[i], nums[i]);
            dp_min = min(mx * nums[i], nums[i]);
        } else {
            dp_max = dp_min = 0;
        }
        res = max(res, dp_max);
    }
    return res;
}
```

合併後

```cpp
int maxProduct(vector<int>& nums) {
    int dp_max = nums[0], dp_min = nums[0];
    int res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int mx = dp_max, mn = dp_min;
        dp_max = max(max(mx * nums[i], mn * nums[i]), nums[i]);
        dp_min = min(min(mn * nums[i], mx * nums[i]), nums[i]);
        res = max(res, dp_max);
    }
    return res;
}
```
