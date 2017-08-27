class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(!matrix.size()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j) {
                if(matrix[i][j] == '0') continue;
                if(j) f[i][j] = f[i][j-1] + 1;
                else f[i][j] = 1;
                int m=f[i][j];
                
                for(int k=i; k>=0; --k) {
                    if(f[k][j] < m) {
                        m = f[k][j];
                        if(!m) break;
                    }
                    ans = max(ans, m*(i-k+1));
                }
            }
        return ans;
    }
};
