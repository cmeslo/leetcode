# 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

## Solution

找到行和列的最大間距，相乘。

```cpp
int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    horizontalCuts.insert(begin(horizontalCuts), 0);
    verticalCuts.insert(begin(verticalCuts), 0);
    horizontalCuts.push_back(h);
    verticalCuts.push_back(w);

    sort(begin(horizontalCuts), end(horizontalCuts));
    sort(begin(verticalCuts), end(verticalCuts));

    int w_max = 0;
    for (int i = 1; i < horizontalCuts.size(); ++i)
        w_max = max(w_max, horizontalCuts[i] - horizontalCuts[i - 1]);

    int h_max = 0;
    for (int i = 1; i < verticalCuts.size(); ++i)
        h_max = max(h_max, verticalCuts[i] - verticalCuts[i - 1]);

    return (long) w_max * h_max % 1000000007;
}
```

or

```cpp
int maxArea(int h, int w, vector<int>& H, vector<int>& V) {
    sort(begin(H), end(H));
    sort(begin(V), end(V));

    int maxgap_w = max(H[0], h - H.back());
    for (int i = 1; i < H.size(); ++i)
        maxgap_w = max(maxgap_w, H[i] - H[i - 1]);

    int maxgap_h = max(V[0], w - V.back());
    for (int i = 1; i < V.size(); ++i)
        maxgap_h = max(maxgap_h, V[i] - V[i - 1]);

    return (long) maxgap_w * maxgap_h % 1000000007;
}
```
