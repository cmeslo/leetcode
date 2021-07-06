# 1074. Number of Submatrices That Sum to Target

## Solution : 拍扁 + prefix + hashmap

### 解釋

```
 x x x x x x x x
[x x x x x x x x
 x x x x x x x x
 x x x x x x x x]
 x x x x x x x x

 Y Y Y Y Y Y Y Y

拍扁成一維後，再用 prefix + hashmap 求解。
```

### 寫法一 (1074_01.cpp)：

#### Code

```cpp
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        
        for (int i = 0; i < m; ++i) {
            vector<int> squash(n);
            for (int j = i; j < m; ++j) {
                for (int x = 0; x < n; ++x) {
                    squash[x] += matrix[j][x];
                }
                ans += count(squash, target);
            }
        }
        return ans;
    }
    
private:
    int count(vector<int>& nums, int target) {
        unordered_map<int, int> prefix_sum;
        prefix_sum[0] = 1;
        
        int ans = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (prefix_sum.count(sum - target))
                ans += prefix_sum[sum - target];
            ++prefix_sum[sum];
        }
        return ans;
    }
};
```

or

```cpp
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int ans = 0;
    for (int y1 = 0; y1 < m; ++y1) {
        vector<int> rows(n);
        for (int y2 = y1; y2 < m; ++y2) {
            unordered_map<int, int> freq;
            freq[0] = 1;
            int sum = 0;
            for (int x = 0; x < n; ++x) {
                rows[x] += matrix[y2][x];
                sum += rows[x];
                ans += freq[sum - target];
                freq[sum]++;
            }
        }
    }
    return ans;
}
```
