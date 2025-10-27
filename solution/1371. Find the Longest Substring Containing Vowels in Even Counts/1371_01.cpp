class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> m(1 << 5, -2);
        m[0] = -1;
        
        int res = 0;
        for (int i = 0, state = 0; i < s.size(); ++i) {
            state = add(state, s[i]);
            if (m[state] != -2)
                res = max(res, i - m[state]);
            else
                m[state] = i;
        }
        return res;
    }
    
private:
    int add(int state, char& c) {
        if (c == 'a') state ^= (1 << 0);
        else if (c == 'e') state ^= (1 << 1);
        else if (c == 'i') state ^= (1 << 2);
        else if (c == 'o') state ^= (1 << 3);
        else if (c == 'u') state ^= (1 << 4);
        return state;
    }
};
