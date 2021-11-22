# 384. Shuffle an Array

## Solution

```cpp
class Solution {
public:
    Solution(vector<int>& nums) {
        A_ = nums;
    }
    
    vector<int> reset() {
        return A_;
    }
    
    vector<int> shuffle() {
        int n = A_.size();
        vector<int> res = A_;
        for (int i = 0; i < n; ++i) {
            int j = rand() % (n - i) + i;
            swap(res[i], res[j]);
        }
        return res;
    }
    
private:
    vector<int> A_;
};
```

shuffle 也可以反向：

```cpp
vector<int> shuffle() {
    vector<int> ans = A_;

    for (int i = A_.size() - 1; i >= 0; --i) {
        int j = rand() % (i + 1);
        swap(ans[i], ans[j]);
    }

    return ans;
}
```
