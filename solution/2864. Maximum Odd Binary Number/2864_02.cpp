class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        const int n = s.size();
        
        int i = 0;
        for (int j = 0; j < n; ++j)
            if (s[j] == '1')
                swap(s[i++], s[j]);
        
        if (s[n - 1] != '1')
            swap(s[i - 1], s[n - 1]);
        return s;
    }
};
