# 1338. Reduce Array Size to The Half

## Solution

由出現次數最多的數字開始移除，當發現移除了超過一半的數字就可以停止。

```cpp
int minSetSize(vector<int>& arr) {
    unordered_map<int, int> m;
    for (int x : arr) m[x]++;
    
    vector<int> freq;
    for (auto [num, count] : m)
        freq.push_back(count);
    sort(freq.rbegin(), freq.rend());
    
    int ans = 0;
    int removed = 0, n = arr.size();
    for (int f : freq) {
        ++ans;
        removed += f;
        if (removed >= n / 2) break;
    }
    return ans;
}
```
