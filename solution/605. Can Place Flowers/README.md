# 605. Can Place Flowers

Time: ```O(N)```

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

or

```cpp
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    for (int i = 1; i < flowerbed.size() - 1; ++i) {
        if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
            if (--n <= 0) break;
            ++i;
        }
    }
    return n <= 0;
}
```
