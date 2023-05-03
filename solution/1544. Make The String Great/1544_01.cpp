class Solution {
public:
    string makeGood(string s) {
        string res;
        for (char& c : s) {
            if (!res.empty() && ((res.back() ^ 32) == c || res.back() == (c ^ 32)))
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};
