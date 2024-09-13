# 525. Contiguous Array

## C++

```cpp
// Runtime: 280 ms, Your runtime beats 17.45 % of cpp submissions.
// Memory Usage: 83.8 MB, Your memory usage beats 83.76 % of cpp submissions.

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> m;
    int res = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i] == 1 ? 1 : -1;
        if (sum == 0)
            res = i + 1;
        else if (m.count(sum))
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }
    return res;
}
```

or

添加一個 offset 保持正數

```cpp
// Runtime: 108 ms, Your runtime beats 99.04 % of cpp submissions.
// Memory Usage: 85.7 MB, Your memory usage beats 10.99 % of cpp submissions.

int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos(2 * n + 1, INT_MIN);

    int res = 0, sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i] == 1 ? 1 : -1;
        if (sum == 0)
            res = i + 1;
        else if (pos[sum + n] != INT_MIN)
            res = max(res, i - pos[sum + n]);
        else
            pos[sum + n] = i;
    }
    return res;
}
```

## Java

```java
public int findMaxLength(int[] nums) {
    HashMap<Integer, Integer> prefix_sum = new HashMap<Integer, Integer>();
    int sum = 0;
    int ans = 0;
    
    prefix_sum.put(0, -1);
    for (int i = 0; i < nums.length; i++) {
        sum += (nums[i] != 0 ? nums[i] : -1);
        if (prefix_sum.containsKey(sum)) {
            int pre_index = prefix_sum.get(sum);
            ans = Math.max(ans, i - pre_index);
        } else {
            prefix_sum.put(sum, i);
        }
    }
    
    return ans;
}
```
