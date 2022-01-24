class Solution {
public:
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
};
