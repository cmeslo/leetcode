# 838. Push Dominoes

## Solution 1

```cpp
string pushDominoes(string D) {
    int n = D.size();

    // push R...L
    for (int i = 0; i < n; ++i) {
        if (D[i] == 'R') {
            while (i + 1 < n && D[i + 1] == 'R') ++i;
            int l = i, r = i + 1;
            for (r = i + 1; r < n && D[r] == '.'; ++r);
            i = r - 1;
            if (r >= n || D[r] != 'L') continue;
            while (l < r) {
                D[l++] = 'R';
                D[r--] = 'L';
                if (l == r) D[l] = '#'; // case: R.L --> R#L
            }
        }
    }

    // push R
    for (int i = 0; i < n; ++i) {
        if (D[i] != 'R') continue;
        while (i + 1 < n && D[i + 1] == '.') {
            D[i + 1] = 'R';
            ++i;
        }
    }

    // push L
    for (int i = n - 1; i >= 0; --i) {
        if (D[i] != 'L') continue;
        while (i - 1 >= 0 && D[i - 1] == '.') {
            D[i - 1] = 'L';
            --i;
        }
    }

    for (int i = 0; i < n; ++i)
        if (D[i] == '#') D[i] = '.';

    return D;
}
```

## Solution 2

```cpp
string pushDominoes(string d) {
    d = 'L' + d + 'R';
    string res = "";

    for (int i = 0, j = 1; j < d.length(); ++j) {
        if (d[j] == '.') continue;
        int middle = j - i - 1;
        if (i > 0)
            res += d[i];
        if (d[i] == d[j])
            res += string(middle, d[i]);
        else if (d[i] == 'L' && d[j] == 'R')
            res += string(middle, '.');
        else if (d[i] == 'R' && d[j] == 'L')
            res += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
        i = j;
    }

    return res;
}


// R...L
// L...L
// R...R
// L...R
```
