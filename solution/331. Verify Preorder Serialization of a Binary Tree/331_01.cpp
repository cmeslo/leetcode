class Solution {
public:
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
};
