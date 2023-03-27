# 1578. Minimum Time to Make Rope Colorful

```cpp
int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int sum = neededTime[i];
        int mx = neededTime[i];
        int j;
        for (j = i + 1; j < n && colors[i] == colors[j]; ++j) {
            sum += neededTime[j];
            mx = max(mx, neededTime[j]);
        }
        i = j - 1;
        res += sum - mx;
    }
    return res;
}
```
