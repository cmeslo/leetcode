# 1217. Minimum Cost to Move Chips to The Same Position

先分奇、偶，無代價的疊在一起，

剩下兩堆後，返回堆數目較少的，那就是把他們疊在一起的代價。

```cpp
int minCostToMoveChips(vector<int>& position) {
    int count_odd = 0, count_even = 0;

    for (int n : position) {
        if (n % 2 == 0)
            ++count_even;
        else
            ++count_odd;
    }

    return min(count_even, count_odd);
}
```
