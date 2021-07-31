# 1354. Construct Target Array With Multiple Sums

## Solution:

### Explanation:

```
last round:   x + x + x + a = sum
last-1 round: x + x + x + b = a
```
coner case:
```
case: [1,1000000000]
case: [1,1,2], [2,4]
case: [4]
```

### Code

```cpp
bool isPossible(vector<int>& target) {
    long sum = accumulate(target.begin(), target.end(), 0LL);
    priority_queue<int> pq(target.begin(), target.end());

    while (pq.top() != 1) {
        int a = pq.top(); pq.pop();
        long others = sum - a;
        if (a <= others) return false;
        if (others == 0) return false; // case: [a]
        if (others == 1) return true; // case: [1,a]
        int b = a % others;
        if (b == 0) return false; // case: [1,1,2], [2,4]
        pq.push(b);
        sum = others + b;
    }
    return true;
}
```
