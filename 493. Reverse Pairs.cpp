class Solution {
    int n;
    vector<int> c;
    void insert(int x) {
        for(int i=x+1; i<=n; i+=(i&(-i)))
            c[i]++;
    }
    int sum(int x) {
        int res=0;
        for(int i=x; i>0; i-=(i&(-i)))
            res += c[i];
        return res;
    }
public:
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        c.resize(n+1);
        vector<pair<int,int> > tot;
        for(int i=0; i<n; ++i) 
            tot.push_back(make_pair(nums[i], -i));
        sort(tot.begin(), tot.end());
        int r = n-1, ans = 0;
        for(int i=n-1; i>=0; --i) {
            while(r>=0 && tot[r].first > ((long long)tot[i].first)*2) {
                insert(-tot[r].second);
                r--;
            }
            ans += sum(-tot[i].second);
        }
        return ans;
    }
};
