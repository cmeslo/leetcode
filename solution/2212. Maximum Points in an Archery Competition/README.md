# 2212. Maximum Points in an Archery Competition

## Solution: 狀態枚舉

```cpp
vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    int ansState = 0, ansScore = 0;
    for (int state = 0; state < (1 << 12); ++state) {
        int score = 0;
        int arrows = numArrows;
        for (int i = 0; i < 12; ++i) {
            if ((state >> i) & 1) {
                arrows -= aliceArrows[i] == 0 ? 1 : aliceArrows[i] + 1;
                if (arrows < 0) {
                    score = -1;
                    break;
                }
                score += i;
            }
        }
        if (score > ansScore) {
            ansScore = score;
            ansState = state;
        }
    }
    vector<int> ans(12);
    int arrows = numArrows;
    for (int i = 0; i < 12; ++i) {
        if ((ansState >> i) & 1) {
            ans[i] = aliceArrows[i] == 0 ? 1 : aliceArrows[i] + 1;
            arrows -= ans[i];
        }
    }
    if (arrows > 0)
        ans[0] = arrows;
    return ans;
}
```
