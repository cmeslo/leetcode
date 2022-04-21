class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int> freq(128);
        for (char& c : s)
            ++freq[c];
        
        vector<string> bucket(n + 1);
        for (int c = 0; c < 128; ++c)
            if (freq[c])
                bucket[freq[c]].push_back(c);
        
        string res;
        for (int i = n; i >= 1; --i)
            for (char& c : bucket[i])
                res.append(i, c);
        return res;
    }
};
