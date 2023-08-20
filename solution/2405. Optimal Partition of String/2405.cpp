class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> w;
        int res = 1;
        for (char& c : s) {
            if (w.count(c)) {
                res++;
                w.clear();
            }
            w.insert(c);
        }
        return res;
    }
};
