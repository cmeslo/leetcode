# 948. Bag of Tokens

Simulation

```cpp
int bagOfTokensScore(vector<int>& tokens, int P) {
    sort(tokens.begin(), tokens.end());
    int n = tokens.size();

    int score = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        while (l <= r && tokens[l] <= P) {
            P -= tokens[l++];
            ++score;
        }
        if (score == 0 || l >= r) break;
        P += tokens[r--];
        --score;
    }

    return score;
}
```
