class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(!nums.size()) return 0;
        int n=nums.size()-1;
        int l = 1, r = n, mid, ans;
        while(l<=r) {
            mid = (l+r)/2;
            int count = 0;
            for(auto x:nums)
                if(x<=mid)
                    count++;
            if(count > mid) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
