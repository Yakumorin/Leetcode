class Solution {
    int dp[510][510];
    int g(int x, vector<int>& nums) {
        if(x == 0 || x > nums.size()) return 1;
        return nums[x-1];
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; ++i)
            dp[i][i+2] = g(i, nums)*g(i+1, nums)*g(i+2, nums);
        for(int k=3; k<=n+1; ++k)
            for(int i=0; i+k<=n+1; ++i) {
                int j=i+k;
                for(int l=i+1; l<j; ++l)
                    dp[i][j] = max(dp[i][j], dp[i][l] + dp[l][j] + g(i, nums)*g(l, nums)*g(j, nums));
            }
        return dp[0][n+1];
    }
};
