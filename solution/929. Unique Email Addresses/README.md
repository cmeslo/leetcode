# 929. Unique Email Addresses

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;
        for (auto& email : emails)
            s.insert(filter(email));
        return s.size();
    }
    
private:
    string filter(string& email) {
        int a = email.find('@');
        
        string local = "";
        for (int i = 0; i < a && email[i] != '+'; ++i) {
            if (email[i] == '.') continue;
            local += email[i];
        }
        
        string domain = email.substr(a + 1);
        return local + '@' + domain;
    }
};
```
