# 605. Can Place Flowers

Time: O(N)

```cpp
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;
    int size = flowerbed.size();

    for (int i = 0; i < size; ++i) {
        int left = (i == 0) ? 0 : flowerbed[i - 1];
        int right = (i == size - 1) ? 0 : flowerbed[i + 1];

        if (left || flowerbed[i] || right) continue;

        flowerbed[i++] = 1;
        if (--n == 0) return true;
    }

    return false;
}
```
