# 1217. Minimum Cost to Move Chips to The Same Position

先分奇、偶，無代價的疊在一起，

剩下兩堆後，返回堆數目較少的，那就是把他們疊在一起的代價。

```cpp
int minCostToMoveChips(vector<int>& position) {
    int odd = 0, even = 0;
    for (int x : position) {
        if (x % 2)
            odd++;
        else
            even++;
    }
    return min(odd, even);
}
```
