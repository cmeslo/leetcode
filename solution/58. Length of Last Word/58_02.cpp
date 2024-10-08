class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        istringstream iss(s);
        string cur;
        while (iss >> cur) {
            res = cur.size();
        }
        return res;
    }
};
