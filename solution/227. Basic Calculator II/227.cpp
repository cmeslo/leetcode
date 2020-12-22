class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        char op = '+';
        int num = 0;
        
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n - 1) {
                if (op == '+') st.push(num);
                else if (op == '-') st.push(-num);
                else if (op == '*' || op == '/') {
                    int tmp = op == '*' ? st.top() * num : st.top() / num;
                    st.pop();
                    st.push(tmp);
                }
                op = s[i];
                num = 0;
            }

        }
        
        int ans = 0;
        while (!st.empty()) {
            ans += st.top(); st.pop();
        }
        
        return ans;
    }
};
