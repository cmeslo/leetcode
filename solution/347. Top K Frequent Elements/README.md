# 347. Top K Frequent Elements

## 347_01.cpp
Bucket sort

```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    for (const int num : nums) {
        count[num]++;
    }

    unordered_map<int, vector<int>> bucket;
    for (auto& kv : count) {
        bucket[kv.second].push_back(kv.first);
    }

    vector<int> ans;
    for (int i = nums.size(); i > 0, k > 0; i--) {
        auto it = bucket.find(i);
        if (it == bucket.end()) continue;
        for (int j : bucket[i]) {
            ans.push_back(j);
            if (--k == 0) break;
        }
    }

    return ans;
}
```
