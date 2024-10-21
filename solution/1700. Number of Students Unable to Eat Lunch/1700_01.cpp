class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        for (int s : students)
            q.push(s);
        for (int i = sandwiches.size() - 1; i >= 0; --i)
            st.push(sandwiches[i]);
        
        while (!q.empty()) {
            int len = q.size();
            for (int i = q.size(); i > 0; --i) {
                if (q.front() == st.top())
                    st.pop();
                else
                    q.push(q.front());
                q.pop();
            }
            if (q.size() == len)
                return q.size();
        }
        return 0;
    }
};
