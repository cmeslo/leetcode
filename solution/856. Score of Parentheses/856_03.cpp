class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int cur = 0;
        for (char& c : s) {
            if (c == '(') {
                st.push(cur);
                cur = 0;
            } else {
                if (cur == 0)
                    cur = 1;
                else
                    cur = 2 * cur;
                cur += st.top();
                st.pop();
            }
        }
        return cur;
    }
};
