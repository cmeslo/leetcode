# 535. Encode and Decode TinyURL

```cpp
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string url;
        
        do {
            url = "";
            for (int i = 0; i < 6; ++i) {
                url.push_back(dict[rand() % dict.size()]);
            }
        } while (cache.count(url));
        
        cache[url] = longUrl;
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (!cache.count(shortUrl)) return "";
        return cache[shortUrl];
    }
    
private:
    const string dict = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unordered_map<string, string> cache;
};
```
