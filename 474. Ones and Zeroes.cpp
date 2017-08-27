class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int f[m+1][n+1];
        memset(f,0,sizeof(f));
        for(auto s : strs) {
            int m1 = 0, n1 = 0;
            for(auto ch : s)
                if(ch=='0') m1++;
                else n1++;
            for(int i=m; i>=m1; --i)
                for(int j=n; j>=n1; --j)
                    f[i][j] = max(f[i][j], f[i-m1][j-n1]+1);
        }
        return f[m][n];
    }
};
