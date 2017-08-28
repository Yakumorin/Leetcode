class Solution {
    string base = "http://tinyurl.com/";
    map<string, string> store;
    map<string, string> done;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(done.count(longUrl)) return done[longUrl];
        string shortLine;
        do{
            shortLine = "";
            for(int i=0; i<6; ++i) {
                int x=rand()%62;
                if(x < 10) shortLine += x+'0';
                else if(x<36) shortLine += x-10+'a';
                else shortLine += x-36+'A';
            }
        }while(store.count(shortLine));
        store[shortLine] = longUrl;
        done[longUrl] = shortLine;
        return shortLine;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return store[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
