# 881. Boats to Save People

## 解釋：

排序，然後不斷從頭尾取數，

船可以坐得下兩個人就上兩個，坐不了就上一個，

由於數字範圍：```1 <= people[i] <= limit <= 3 * 10^4```，所以不會出現坐不下的情況。

### Code:

```cpp
int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
    sort(begin(people), end(people));

    int boats = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (people[l] + people[r] <= limit)
            ++l;
        --r;
        ++boats;
    }
    return boats;
}
```
