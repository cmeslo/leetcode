# 649. Dota2 Senate

## Solution: Queue

```cpp
string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> qR, qD;
    
    for (int i = 0; i < senate.size(); ++i) {
        senate[i] == 'R' ? qR.push(i) : qD.push(i);
    }
    
    while (!qR.empty() && !qD.empty()) {
        int i = qR.front(); qR.pop();
        int j = qD.front(); qD.pop();
        i < j ? qR.push(i + n) : qD.push(j + n);
    }
    return qR.size() > qD.size() ? "Radiant" : "Dire";
}
```
