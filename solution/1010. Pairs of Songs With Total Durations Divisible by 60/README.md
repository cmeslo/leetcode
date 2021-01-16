# 1010. Pairs of Songs With Total Durations Divisible by 60

## 解釋

先試了下 Brute force 方法，和預期的一樣、TLE了

```cpp
for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
        if ((time[i] + time[j]) % 60 == 0)
            ++ans;
    }
}
```

觀察一下題目的例子：

```
Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
```

當兩個數字相加之後會變成60的倍數，那就代表它們是一組答案

可以發現，如果分別把它們對60取餘數，相加之後可以互補成 60或者0

```
(a + b) % 60 = 0 ---> a % 60 + b % 60 = 60 或者 0
```

例如：
```
(30, 150) ---> 30 % 60 + 150 % 60 = 30 + 30 = 60
(20, 100) ---> 20 % 60 + 100 % 60 = 20 + 40 = 60
(20, 40) ----> 20 % 60 + 40 % 60 = 20 + 40 = 60
```

另外要注意，當兩個數字原本就是60倍數的情況：
```
(60, 60) ---> 60 % 60 + 60 % 60 = 0 + 0 = 0
(60, 120) ---> 60 % 60 + 120 % 60 = 0 + 0 = 0
```

## Code

```cpp
int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> remainders(60);
    int ans = 0;

    for (int t : time) {
        if (t % 60 == 0) {
            ans += remainders[0];
        } else {
            ans += remainders[60 - t % 60];
        }
        ++remainders[t % 60];
    }

    return ans;
}
```

簡化代碼：

```60 - t % 60```，如果 t % 60 = 0，答案會等於 60，但其實應該是 0，

如果不想用 if 句，公式可以改成 ```(60 - t % 60) % 60```

```cpp
int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> remainders(60);
    int ans = 0;

    for (int t : time) {
        ans += remainders[(60 - t % 60) % 60];
        ++remainders[t % 60];
    }

    return ans;
}
```

如果不想兩次取mod，可以再進一步簡化：


```(600 - t) % 60``` --> 最後才對 60 取 mod

推導過程：```60 - t % 60``` --> ```(60 - t % 60) % 60``` = ```60 % 60 - t % 60``` = ```600 % 60 - t % 60``` = ```(600 - t) % 60```

因為提目說ｔ不會超過 500，所以用600（60的倍數就可以了）

```cpp
int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> remainders(60);
    int ans = 0;

    for (int t : time) {
        ans += remainders[(600 - t) % 60];
        ++remainders[t % 60];
    }

    return ans;
}
```

另外補充一個用map的寫法：

雖然runtime結果沒有甚麼差別，但理論上、上面用vector的寫法會快一點

```cpp
int numPairsDivisibleBy60(vector<int>& time) {
    int ans = 0;
    unordered_map<int, int> m;
    for (int t : time) {
        int remainder = t % 60;
        if (m.count((60 - remainder) % 60))
            ans += m[(60 - remainder) % 60];
        ++m[remainder];
    }
    return ans;
}
```
