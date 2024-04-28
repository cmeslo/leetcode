class Solution {
public:
    bool makeEqual(vector<string>& words) {
        const int n = words.size();
        
        vector<int> f(26);
        for (string& word : words)
            for (char& c : word)
                ++f[c - 'a'];
        
        for (int i = 0; i < 26; ++i)
            if (f[i] % n)
                return false;
        
        return true;
    }
};
