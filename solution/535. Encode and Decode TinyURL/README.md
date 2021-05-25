# 535. Encode and Decode TinyURL

```cpp
class Solution {
private:
    unordered_map<string, string> m_;
    const string dict_ = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl;
        
        do {
            shortUrl = "";
            for (int i = 0; i < 6; ++i)
                shortUrl.push_back(dict_[rand() % 62]);
        } while (m_.find(shortUrl) != m_.end());
        
        m_[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m_[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```
