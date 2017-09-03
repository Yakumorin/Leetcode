class Solution {
    int sum(vector<vector<int>>& matrix, int x) {
        int n = matrix.size(), co = 0, r;
        r = n-1;
        for(int i=0; i<n; ++i) {
            while(r>=0 && matrix[i][r] > x) --r;
            if(r<0) return co;
            co += r+1;
        }
        return co;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1], mid, ans;
        while(l <= r) {
            mid = ((long long)l+r)/2;
            if(sum(matrix, mid) >= k) {
                ans = mid;
                r = mid-1;
            } else l = mid+1;
        }
        return ans;
    }
};
