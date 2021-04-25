class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> lefts;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                lefts.push(i);
            else if (s[i] == ')') {
                if (!lefts.empty())
                    lefts.pop();
                else
                    s[i] = '*';
            }
        }
        
        while (!lefts.empty()) {
            s[lefts.top()] = '*';
            lefts.pop();
        }
        
        string ans;
        for (char& c : s)
            if (c != '*')
                ans += c;
        
        return ans;
    }
};
