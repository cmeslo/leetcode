class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (string& d : details) {
            if (d[11] > '6' || (d[11] == '6' && d[12] > '0'))
                ++res;
        }
        return res;
    }
};
