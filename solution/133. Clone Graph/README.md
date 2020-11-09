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

## 133_02.cpp

bfs

```cpp
Node* cloneGraph(Node* node) {
    if (!node) return nullptr;

    unordered_map<int, Node*> copies;
    queue<Node*> todo;

    copies[node->val] = new Node(node->val);
    todo.push(node);

    while (!todo.empty()) {
        Node* cur = todo.front(); todo.pop();

        for (Node* next : cur->neighbors) {
            if (copies.find(next->val) == copies.end()) {
                copies[next->val] = new Node(next->val);
                todo.push(next);
            }
            copies[cur->val]->neighbors.push_back(copies[next->val]);
        }
    }

    return copies[node->val];
}
```

or vector

```cpp
Node* cloneGraph(Node* node) {
    if (!node) return node;

    vector<Node*> copies(101, nullptr);
    copies[node->val] = new Node(node->val);
    queue<Node*> todo;
    todo.push(node);

    while (!todo.empty()) {
        auto* cur = todo.front(); todo.pop();
        for (auto* next : cur->neighbors) {
            if (!copies[next->val]) {
                copies[next->val] = new Node(next->val);
                todo.push(next);
            }
            copies[cur->val]->neighbors.push_back(copies[next->val]);
        }
    }

    return copies[node->val];
}
```
