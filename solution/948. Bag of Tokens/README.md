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
        if (score == 0 || i >= j) break;
        power += tokens[j--];
        --score;
    }

    return score;
}
```
