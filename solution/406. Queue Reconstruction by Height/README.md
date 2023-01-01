# 406. Queue Reconstruction by Height

## Solution: Greedy

### C++

```cpp
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
    });

    vector<vector<int>> res;
    for (const vector<int>& p : people) {
        res.insert(res.begin() + p[1], p);
    }
    return res;
}
```

### Java

```java
public int[][] reconstructQueue(int[][] people) {
    Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1]-b[1] : b[0]-a[0]);

    List<int[]> res = new ArrayList<>();
    for (int[] p : people) {
        res.add(p[1], p);
    }
    return res.toArray(new int[people.length][2]);
}
```
