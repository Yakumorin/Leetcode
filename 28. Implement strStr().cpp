class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0; i+needle.size()<=haystack.size(); ++i) {
            bool ok=1;
            for(int j=0; j<needle.size(); ++j)
                if(haystack[i+j] != needle[j]) {
                    ok=0;
                    break;
                }
            if(ok) return i;
        }
        return -1;
    }
};
