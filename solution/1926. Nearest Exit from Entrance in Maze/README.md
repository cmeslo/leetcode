# 1926. Nearest Exit from Entrance in Maze

## Solution: BFS

```cpp
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    const vector<int> dirs = {0, -1, 0, 1, 0};
    int m = maze.size(), n = maze[0].size();

    queue<pair<int, int>> q;
    maze[entrance[0]][entrance[1]] = '+';
    q.push({entrance[0], entrance[1]});
    int res = 0;
    while (!q.empty()) {
        int size = q.size();
        ++res;
        while (size--) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int y = i + dirs[k];
                int x = j + dirs[k + 1];
                if (y < 0 || y >= m || x < 0 || x >= n || maze[y][x] == '+') continue;
                if (y == 0 || y == m - 1 || x == 0 || x == n - 1) return res;
                maze[y][x] = '+';
                q.push({y, x});
            }
        }
    }
    return -1;
}
```
