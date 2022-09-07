# 2208. Minimum Operations to Halve Array Sum

```cpp
int halveArray(vector<int>& nums) {
    using ll = long long;
    double sum = 0;
    priority_queue<double> pq;
    for (int x : nums) {
        sum += x;
        pq.push(x);
    }

    int ans = 0;
    double target = sum / 2;
    while (sum > target) {
        double x = pq.top(); pq.pop();
        sum = sum - x + x / 2;
        pq.push(x / 2);
        ++ans;
    }
    return ans;
}
```
