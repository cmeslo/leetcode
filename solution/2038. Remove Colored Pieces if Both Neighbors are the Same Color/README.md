# 2038. Remove Colored Pieces if Both Neighbors are the Same Color

## Solution: Greedy

### 寫法一

```cpp
bool winnerOfGame(string colors) {
    int n = colors.size();
    
    int cntA = 0, cntB = 0;
    int A = 0, B = 0;
    colors.push_back('#');
    
    for (int i = 0; i <= n; ++i) {
        if (i && colors[i-1] != colors[i]) {
            if (colors[i-1] == 'A')
                cntA += max(0, A - 2);
            else
                cntB += max(0, B - 2);
        }
        if (colors[i] == 'A') {
            B = 0;
            ++A;
        } else if (colors[i] == 'B') {
            A = 0;
            ++B;
        }
    }
    return cntA > cntB;
}
```

### 寫法二

```cpp
bool winnerOfGame(string colors) {
    int n = colors.size();
    int A = 0, B = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        if (colors[i] == 'A') {
            while (j < n && colors[j] != 'B')
                ++j;
            A += max(0, j - i - 2);
        } else {
            while (j < n && colors[j] != 'A')
                ++j;
            B += max(0, j - i - 2);
        }
        i = j - 1;
    }
    return A > B;
}
```
