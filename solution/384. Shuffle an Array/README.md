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
