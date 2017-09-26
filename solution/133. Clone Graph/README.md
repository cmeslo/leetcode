# 133. Clone Graph

## 133_01_dfs.cpp

I using map to record created node
```cpp
unordered_map<int, UndirectedGraphNode*> m;
```
we can also use **pointer** as key whether the **label** is unique or not:
```cpp
unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
```
