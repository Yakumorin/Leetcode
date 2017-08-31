class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int ans=0;
        string res;
        for(int i=0; i<s.size(); ++i) {
            int t=0;
            while(i-t>=0 && i+t<s.size() && s[i-t] == s[i+t]) ++t;
            if(t*2-1 > ans) {
                ans = t*2-1;
                res = s.substr(i-t+1, t*2-1);
            }
            t=0;
            if(i+1<s.size() && s[i] == s[i+1]) {
                while(i-t>=0 && i+t+1<s.size() && s[i-t] == s[i+t+1]) ++t;
                if(t*2 > ans) {
                    ans = t*2;
                    res = s.substr(i-t+1, t*2);
                }
            }
        }
        return res;
    }
};
