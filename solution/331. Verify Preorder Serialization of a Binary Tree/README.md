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
