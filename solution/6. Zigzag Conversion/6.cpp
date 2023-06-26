class Solution {
public:
    string convert(string s, int n) {
        vector<string> A(n);
        for (int i = 0; i < s.size();) {
            for (int j = 0; j < n && i < s.size(); ++j, ++i)
                A[j].push_back(s[i]);
            for (int j = n - 2; j >= 1 && i < s.size(); --j, ++i)
                A[j].push_back(s[i]);
        }
        
        string res;
        for (const string& row : A)
            res.append(row);
        return res;
    }
};
