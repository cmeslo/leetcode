# 957. Prison Cells After N Days

## 957_01.cpp

用 while 循環，而 <strong>N--</strong> 在遇到 ```Cycle``` 時剛好減了一輪，對結果沒有影響：

```cpp
vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<int> tmp(8);
    vector<vector<int>> seen;

    while (N--) {
        for (int i = 1; i < 7; i++) {
            tmp[i] = cells[i-1] == cells[i+1];
        }
        if (seen.size() && seen.front() == tmp) return seen[N % seen.size()];
        else seen.push_back(tmp);
        cells = tmp;
    }

    return cells;
}
```

## 957_02.cpp

用 for 循環做，取模時用注意用 ```N-1``` ，代碼如下：

```cpp
vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<vector<int>> seen; // seen[0]=Day1, seen[1]=Day2, ..., seen[N-1]=DayN
    vector<int> tmp(8, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < 7; j++)
            tmp[j] = cells[j-1] == cells[j+1] ? 1 : 0;

        if (!seen.empty() && tmp == seen.front())
            return seen[(N-1) % seen.size()];

        seen.push_back(tmp);
        cells = tmp;
    }
    return cells;
}
```
