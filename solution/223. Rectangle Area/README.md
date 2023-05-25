# 223. Rectangle Area

## Solution 1: Sweep line

```cpp
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // h * w -> covered
    int w = 0, h = 0;
    int area = 0;
    multiset<pair<int, int>> events;
    events.insert({ax1, 1}), events.insert({ax2, -1});
    events.insert({bx1, 1}), events.insert({bx2, -1});
    int pre_x = (*events.begin()).first;
    for (auto& [x, e] : events) {
        if (e == -1 && area == 2)
            w = x - pre_x;
        area += e;
        pre_x = x;
    }

    events.clear();
    area = 0;
    events.insert({ay1, 1}), events.insert({ay2, -1});
    events.insert({by1, 1}), events.insert({by2, -1});
    int pre_y = (*events.begin()).first;
    for (auto& [y, e] : events) {
        if (e == -1 && area == 2)
            h = y - pre_y;
        area += e;
        pre_y = y;
    }

    return (ay2 - ay1) * (ax2 - ax1) + (by2 - by1) * (bx2 - bx1) - h * w;
}
```

## Solution 2

```cpp
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int left = max(ax1, bx1), right = max(left, min(ax2, bx2));
    int bottom = max(ay1, by1), top = max(bottom, min(ay2, by2));
    return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - (right-left)*(top-bottom);
}
```
