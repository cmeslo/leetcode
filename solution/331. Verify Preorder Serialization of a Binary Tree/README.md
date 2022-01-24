# 331. Verify Preorder Serialization of a Binary Tree

## Solution 1: stack

觀察到所有葉子節點，都有兩個 # 符號在後面，所以可以用 stack 去消除。

```cpp
bool isValidSerialization(string preorder) {
    vector<string> st;
    istringstream iss(preorder);

    string node;
    while (getline(iss, node, ',')) {
        st.push_back(node);
        int len = st.size();
        while (len >= 3 && st[len - 1] == "#" && st[len - 2] == "#" && st[len - 3] != "#") {
            st.pop_back(); st.pop_back(); st.pop_back();
            st.push_back("#");
            len = st.size();
        }
    }
    return st.size() == 1 && st.back() == "#";
}
```

or

```cpp
bool isValidSerialization(string preorder) {
    istringstream ss(preorder);
    string node;
    stack<string> st;
    while (getline(ss, node, ',')) {
        if (node == "#") {
            while (st.size() >= 2 && st.top() == "#") {
                st.pop();
                if (st.top() == "#") return false;
                st.pop();
            }
        }
        st.push(node);
    }
    return st.size() == 1 && st.top() == "#";
}
```

## Solution 2: 計算入度和出度

```cpp
bool isValidSerialization(string preorder) {
    istringstream iss(preorder);
    string node;
    int diff = 1;
    while (getline(iss, node, ',')) {
        if (--diff < 0) return false;
        if (node != "#") diff += 2;
    }
    return diff == 0;
}
```
