# 682. Baseball Game

## Solution: Stack

```cpp
int calPoints(vector<string>& ops) {
    vector<int> A;
    for (string& op : ops) {
        if (op == "+")
            A.push_back(A[A.size() - 2] + A[A.size() - 1]);
        else if (op == "D")
            A.push_back(A.back() * 2);
        else if (op == "C")
            A.pop_back();
        else
            A.push_back(stoi(op));
    }
    return accumulate(A.begin(), A.end(), 0);
}
```
