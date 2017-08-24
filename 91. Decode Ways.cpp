class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(!n) return 0;
        int f[n+1];
        f[0]=1;
        for(int i=1; i<=n; ++i) {
            f[i] = 0;
            if(s[i-1]!='0') f[i] += f[i-1];
            if(i==1) continue;
            if(s[i-2] == '0') continue;
            int x = (s[i-2]-'0')*10+s[i-1]-'0';
            if(x<=26 && x>=1) f[i] += f[i-2];
        }
        return f[n];
    }
};
