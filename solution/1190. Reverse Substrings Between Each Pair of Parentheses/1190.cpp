class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> L;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                L.push(i);
            } else if (s[i] == ')') {
                reverse(s.begin() + L.top(), s.begin() + i);
                L.pop();
            }
        }
        
        string res;
        for (char& c : s) {
            if (c == '(' || c == ')') continue;
            res += c;
        }
        return res;
    }
};



// (u(love)i)
// (ueovli
