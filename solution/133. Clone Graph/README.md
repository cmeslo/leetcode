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

Code:

```cpp
unordered_map<int, Node*> copies;

Node* cloneGraph(Node* node) {
    if (!node) return nullptr;
    if (copies.find(node->val) != copies.end()) return copies[node->val];

    Node* new_node = new Node(node->val);
    copies[node->val] = new_node;

    for (Node* n : node->neighbors)
        new_node->neighbors.push_back(cloneGraph(n));

    return new_node;
}
```
