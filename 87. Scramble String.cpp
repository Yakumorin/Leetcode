class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return 1;
        if(s1.size() != s2.size()) return 0;
        int w[26]={}, n=s1.size();
        for(int i=0; i<n; ++i) {
            w[s1[i]-'a']++;
            w[s2[i]-'a']--;
        }
        for(int i=0; i<26; ++i)
            if(w[i])
                return 0;
        for(int i=1; i<n; ++i)
            if((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) ||
               (isScramble(s1.substr(n-i), s2.substr(0, i)) && isScramble(s1.substr(0, n-i), s2.substr(i))))
                return 1;
        return 0;
    }
};
