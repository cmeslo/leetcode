# 948. Bag of Tokens

## Solution: Simulation

```cpp
int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int score = 0;
    int i = 0, j = tokens.size() - 1;

    while (i <= j) {
        while (i <= j && power >= tokens[i]) {
            power -= tokens[i++];
            ++score;
        }
        if (score == 0 || i >= j) break; // i >= j 就 break, 保證了即使用1分換了 tokens[r], 最少可以換回 tokens[l] 保住1分
        power += tokens[j--];
        --score;
    }

    return score;
}
```

or

```cpp
int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int l = 0, r = tokens.size() - 1;
    int res = 0, score = 0;
    while (l <= r && power >= tokens[l]) {
        power -= tokens[l++];
        score += 1;
        res = max(res, score);
        while (l <= r && power < tokens[l]) {
            power += tokens[r--];
            score -= 1;
        }
    }
    return res;
}
```
