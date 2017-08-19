class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<=n;++i)
            for(int j=1;j<=m;++j) 
                if(p[j-1]=='*') {
                    if(j>1) {
                        dp[i][j] = dp[i][j-2];
                        if(i) dp[i][j] |= ((s[i-1]==p[j-2] || p[j-2]=='.') && dp[i-1][j]);
                    } else dp[i][j] = 0;
                }
                else {
                    if(i) dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='.') && dp[i-1][j-1];
                    else dp[i][j] = 0;
                }
        return dp[n][m];
    }
};
