class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> f(26);
        for (int x : ransomNote)
            f[x - 'a']++;
        
        int cnt = 0;
        for (int x : magazine) {
            if (f[x - 'a']-- > 0) {
                if (++cnt == ransomNote.size())
                    return true;
            }
        }
        
        return false;
    }
};
